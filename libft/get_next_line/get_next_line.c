/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:23:58 by hdoo              #+#    #+#             */
/*   Updated: 2022/05/16 23:27:07 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static t_file	*find_fd(t_file **fd_data, int fd)
{
	t_file	*curr;

	curr = FT_NULL;
	if ((*fd_data) != FT_NULL)
	{
		curr = (*fd_data);
		while (curr != FT_NULL && curr->fd != fd)
		{
			if (curr->next == FT_NULL)
			{
				curr->next = init_fd(fd);
				curr->next->prev = curr;
				curr = curr->next;
				return (curr);
			}
			curr = curr->next;
		}
	}
	if ((*fd_data) == FT_NULL)
	{
		curr = init_fd(fd);
		*fd_data = curr;
	}
	return (curr);
}

static bool	find_next_newline(t_file *curr)
{
	int	found_newline;

	while (curr->line_end < curr->rd_size && \
		curr->last_list->segment[curr->line_end % BUFFER_SIZE] != '\n')
	{
		curr->line_end++;
	}
	found_newline = (curr->line_end < curr->rd_size);
	curr->line_end += found_newline;
	return (found_newline);
}

static int	read_fd(t_file *curr)
{
	ssize_t	read_size;

	while (find_next_newline(curr) == 0 && curr->is_eof != TRUE)
	{
		if (addback_seg(curr) == 0)
		{
			return (0);
		}
		read_size = read(curr->fd, curr->last_list->segment, BUFFER_SIZE);
		if (read_size == -1)
		{
			return (0);
		}
		curr->rd_size += read_size;
		curr->is_eof = (read_size == 0 || read_size < BUFFER_SIZE \
				|| curr->fd == 0);
	}
	return (1);
}

char	*create_line(t_file **fd_data, t_file *curr)
{
	char	*result;

	result = FT_NULL;
	if (curr->line_stt < curr->line_end)
	{
		curr->is_eof = link_lines(&curr, &result) == 0;
	}
	if (curr->list != FT_NULL)
	{
		free_used_segment(curr);
	}
	if (curr->is_eof == TRUE && curr->line_end == curr->rd_size)
	{
		free_ended_fd_data(fd_data, curr);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static t_file	*fd_data = FT_NULL;
	t_file			*curr;

	curr = find_fd(&fd_data, fd);
	if (curr == FT_NULL)
	{
		return (FT_NULL);
	}
	if (read_fd(curr) == 0)
	{
		curr->line_stt = curr->line_end;
		curr->is_eof = TRUE;
	}
	return (create_line(&fd_data, curr));
}
