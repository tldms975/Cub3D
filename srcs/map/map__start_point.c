/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__start_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/02 16:41:58 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static bool	is_start_point(char target)
{
	const char	sp_table[] = {'N', 'W', 'E', 'S'};
	bool	retval;
	size_t	i;

	retval = false;
	i = 0;
	while (i < sizeof(sp_table) / sizeof(sp_table[0]))
	{
		if (target == sp_table[i])
		{
			retval = true;
			break ;
		}
		i++;
	}
	return (retval);
}

static t_result	map__start_point__init(t_info *info, int x, int y)
{
	char	target;

	target = map__check_char(info->map.raw[y]->str[x]);
	if (target == FAILURE)
	{
		ft_putstr_fd("Error: Invalid character in map\n", 2);
		return (ERROR);
	}
	else if (is_start_point(target) == true)
	{
		if (info->core.world.player.cardinal == 0)
		{
			info->core.world.player.cardinal = target;
			info->core.world.player.pos.x = x + 0.5;
			info->core.world.player.pos.y = y + 0.5;
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
