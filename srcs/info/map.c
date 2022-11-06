/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:56:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/06 20:55:09 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_result	prim(t_info *info);
t_result	validate_map(t_info *info);
void	print_map(t_info *info, size_t x, size_t y); // TODO - remove

// t_result	validate_map(t_info *info)
// {
// 	(void)info;
// 	return (SUCCESS);
// 	// return (prim(info));
// }

t_result	scan_map(t_info *info)
{
	char		*line;
	t_str_buf	*new_row;

	line = get_next_line(info->fd);
	while (line != NULL && *line == '\n')
	{
		free_safe(line);
		line = get_next_line(info->fd);
	}
	info->map.capacity = sizeof(t_str_buf *);
	while (line != NULL)
	{
		info->map.raw = ft_realloc(info->map.raw, \
				sizeof(t_str_buf) * info->map.height + 1, \
				info->map.capacity, &info->map.capacity);
		new_row = str_append(NULL, line);
		info->map.raw[info->map.height++] = new_row;
		if (info->map.width < new_row->length)
		{
			info->map.width = new_row->length;
		}
		line = get_next_line(info->fd);
	}
	info->map.visited = 
		malloc_safe(sizeof(bool) * (info->map.height* info->map.width));
	return (SUCCESS);
}

t_result	read_map(t_info *info)
{
	if (scan_map(info) == SUCCESS && \
			validate_map(info) == SUCCESS)
	{
		return (SUCCESS);
	}
	return (FAILURE);
}
