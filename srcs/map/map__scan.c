/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:56:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/06 02:33:51 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include "string_buffer.h"

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
	info->map.height = 1;
	info->map.raw = malloc_safe(sizeof(t_str_buf) * info->map.height + 1);
	info->map.raw[0] = str_append(NULL, ft_strdup(" "));
	while (line != NULL)
	{
		info->map.raw = ft_realloc(info->map.raw,
				sizeof(t_str_buf) * info->map.height + 1,
				info->map.capacity, &info->map.capacity);
		info->map.raw[info->map.height]
			= str_append(str_append(NULL, ft_strdup(" ")), line);
		free_safe(line);
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
