/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:19:08 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/03 16:01:29 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include <stdio.h>

t_result	map__sprite__add(t_info *info, size_t i, size_t j, size_t id)
{
	t_result	result;
	t_world		*world;
	size_t		size;

	size = sizeof(t_sprite);
	world = &info->core.world;
	result = false;
	if (info->map.raw[i]->str[j] == 'T')
	{
		world->spr_cnt += 1;
		world->spr = ft_realloc(world->spr,
			(world->spr_cnt * size),
			world->spr_capacity, &world->spr_capacity);
		world->spr[id].coor.x = j;
		world->spr[id].coor.y = i;
		world->spr[id].order = id;
		result = true;
	}
	return (result);
}

t_result	map__sprite__find(t_info *info)
{
	size_t		i;
	size_t		j;
	size_t		id;

	i = 0;
	id = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.raw[i]->length)
		{
			id += map__sprite__add(info, i , j , id);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
