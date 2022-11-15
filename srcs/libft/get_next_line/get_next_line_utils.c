/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:19:50 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/29 01:55:23 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - FIND fd, manage segment memory, create new line, manage remain.

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

t_file	*init_fd(int fd)
{
	t_file	*fd_data;

	if (fd < 0)
		return (FT_NULL);
	fd_data = malloc(sizeof(t_file));
	fd_data->fd = fd;
	fd_data->is_eol = 0;
	fd_data->is_eof = 0;
	fd_data->rd_size = 0;
	fd_data->line_end = 0;
	fd_data->line_stt = 0;
	fd_data->list = FT_NULL;
	fd_data->last_list = FT_NULL;
	fd_data->next = FT_NULL;
	fd_data->prev = FT_NULL;
	return (fd_data);
}

int	addback_seg(t_file *curr)
{
	t_segment	**new_list;

	if (curr->last_list)
	{
		new_list = &(curr->last_list->next);
	}
	else
	{
		new_list = &(curr->list);
	}
	*new_list = malloc(sizeof(t_segment));
	if (*new_list)
	{
		(*new_list)->segment = malloc(sizeof(char) * (BUFFER_SIZE));
		(*new_list)->next = FT_NULL;
		curr->last_list = (*new_list);
	}
	return (curr->last_list != FT_NULL);
}

int	link_lines(t_file **curr, char **result)
{
	const int	line_size = ((*curr)->line_end - (*curr)->line_stt);
	t_segment		*cursor;
	int			i;

	*result = malloc(sizeof(char) * (line_size + 1));
	if (*result)
	{
		i = 0;
		cursor = (*curr)->list;
		while (cursor != FT_NULL && (*curr)->line_stt < (*curr)->line_end)
		{
			(*result)[i] = cursor->segment[(*curr)->line_stt % BUFFER_SIZE];
			(*curr)->line_stt++;
			if ((*curr)->line_stt % BUFFER_SIZE == 0)
			{
				cursor = cursor->next;
			}
			i++;
		}
		(*result)[line_size] = '\0';
	}
	return (result != FT_NULL);
}

void	free_used_segment(t_file *curr)
{
	t_segment		*will_free;
	const int	need_to_clean_last_segment = (curr->is_eof \
			|| curr->line_end == curr->rd_size);

	while (curr->list != FT_NULL && \
			curr->list != curr->last_list)
	{
		will_free = curr->list;
		curr->list = curr->list->next;
		free(will_free->segment);
		free(will_free);
	}
	if (need_to_clean_last_segment == 1)
	{
		free(curr->last_list->segment);
		curr->last_list->segment = FT_NULL;
		free(curr->last_list);
		curr->last_list = FT_NULL;
	}
	return ;
}

void	free_ended_fd_data(t_file **fd_data, t_file *curr)
{
	if (curr->prev)
	{
		curr->prev->next = curr->next;
	}
	else
	{
		*fd_data = curr->next;
	}
	if (curr->next)
	{
		curr->next->prev = curr->prev;
	}
	free(curr);
	curr = FT_NULL;
}
