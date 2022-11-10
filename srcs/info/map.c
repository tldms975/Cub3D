/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:56:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/12 06:54:46 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_result	prim(t_info *info);
t_result	map__validate(t_info *info);
void		print_map(t_info *info, size_t x, size_t y); // TODO - remove

// t_result	validate_map(t_info *info)
// {
// 	(void)info;
// 	return (SUCCESS);
// 	// return (prim(info));
// }
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
	while (line != NULL)
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
