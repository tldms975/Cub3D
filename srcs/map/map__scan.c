/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:56:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:19:23 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*map__skip_newline(t_info *info)
{
	char	*line;

	line = get_next_line(info->fd);
	while (line != NULL && *line == '\n')
	{
		free_safe(line);
		line = get_next_line(info->fd);
	}
	return (line);
}

static t_result	map__scan(t_info *info)
{
	char		*line;

	info->map.capacity = sizeof(t_str_buf *);
	line = map__skip_newline(info);
	while (line != NULL && *line != '\n')
	{
		info->map.raw = ft_realloc(info->map.raw,
				sizeof(t_str_buf) * info->map.height + 1,
				info->map.capacity, &info->map.capacity);
		info->map.raw[info->map.height] = str_append(NULL, line);
		if (info->map.width < info->map.raw[info->map.height]->length)
		{
			info->map.width = info->map.raw[info->map.height]->length;
		}
		line = get_next_line(info->fd);
		info->map.height++;
	}
	return (SUCCESS);
}

t_result	map__read(t_info *info)
{
	if (map__scan(info) == SUCCESS
		&& map__validate(info) == SUCCESS)
	{
		return (SUCCESS);
	}
	return (FAILURE);
}
