/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__start_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 15:59:18 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static t_result	map__start_point__init(t_info *info, int x, int y)
{
	char	target;

	target = map__check_char(info->map.raw[y]->str[x]);
	if (target == FAILURE)
	{
		ft_putstr_fd("Error: Invalid character in map\n", 2);
		return (ERROR);
	}
	else if (target > 'D')
	{
		if (info->core.world.player.cardinal == 0)
		{
			info->core.world.player.cardinal = target;
			info->core.world.player.pos.x = x;
			info->core.world.player.pos.y = y;
			info->map.visited[y][x] = true;
			return (SUCCESS);
		}
		else
		{
			ft_putstr_fd("Error: Multiple start point founded\n", 2);
			return (ERROR);
		}
	}
	return (FAILURE);
}

t_result	map__start_point__find(t_info *info)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.raw[i]->length)
		{
			if (map__start_point__init(info, j, i) == ERROR)
			{
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	if (info->core.world.player.cardinal == 0)
	{
		ft_putstr_fd("Error: No start point founded\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
