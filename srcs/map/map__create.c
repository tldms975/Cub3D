/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:10:55 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "info.h"
#include "map.h"
#include <stdbool.h>
#include <stdio.h>

void	map__openpath_create(t_info *info, t_path *open)
{
	open->capacity
		= sizeof(t_coor) * (info->map.height * info->map.width);
	open->path = malloc_safe(open->capacity);
	ft_bzero(open->path, open->capacity);
	open->count = 1;
	open->path[0].x = info->core.world.player.pos.x;
	open->path[0].y = info->core.world.player.pos.y;
	open->path[0].c = info->core.world.player.cardinal;
}

void	map__visited_create(t_info *info)
{
	size_t	i;

	i = 0;
	info->map.visited = malloc_safe(sizeof(bool *) * info->map.height);
	while (i < info->map.height)
	{
		info->map.visited[i] = malloc_safe(sizeof(bool) * info->map.width);
		ft_memset(info->map.visited[i], 0, sizeof(bool) * info->map.width);
		i++;
	}
}

static void	map__redzone_init(t_info *info)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (map__check_char(info->map.raw[y]->str[x]) > ' ')
			{
				info->map.redzone[y + 1][x + 1] = true;
			}
			x++;
		}
		y++;
	}
}

void	map__redzone_create(t_info *info)
{
	size_t	y;
	size_t	padding;

	padding = 2;
	y = 0;
	info->map.redzone
		= malloc_safe(sizeof(bool *) * (info->map.height + padding));
	while (y < info->map.height + padding)
	{
		info->map.redzone[y]
			= malloc_safe(sizeof(bool) * (info->map.width + padding));
		ft_memset(info->map.redzone[y],
			0, sizeof(bool) * (info->map.width + padding));
		y++;
	}
	map__redzone_init(info);
	print_redzone(info);
}
