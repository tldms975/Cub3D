/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:56:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 01:18:04 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*realloc_map_raw_data(t_info *info)
{
	t_str_buf	**new_map;
	size_t		old_capacity;

	new_map = info->map.raw_data;
	old_capacity = info->map.capacity;
	if (info->map.capacity <= info->map.height)
	{
		info->map.capacity *= 2;
	}
	new_map = malloc_safe(sizeof(t_str_buf *) * (info->map.capacity));
	if (info->map.raw_data != NULL)
	{
		ft_memcpy(new_map, info->map.raw_data, sizeof(t_str_buf *) * old_capacity);
		free_safe(info->map.raw_data);
	}
	return (new_map);
}

t_result	scan_map(t_info *info)
{
	char		*line;
	t_str_buf	*new_row;

	line = get_next_line(info->fd);
	info->map.capacity = 1;
	while (line != NULL)
	{
		info->map.raw_data = (t_str_buf **)realloc_map_raw_data(info);
		new_row = str_append(NULL, line);
		info->map.raw_data[info->map.height++] = new_row;
		if (info->map.width < new_row->length)
		{
			info->map.width = new_row->length;
		}
		line = get_next_line(info->fd);
	}
	// print_map(info, );
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
