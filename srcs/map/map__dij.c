/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__dij.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:29:59 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	_offset(size_t i)
{
	const int	offset[6] = {1, -1, 0, 0, 1, -1};

	return (offset[i]);
}

static t_result	map__dij__check_coor(t_info *info,
		bool precheck, size_t y, size_t x)
{
	const char	valid_land[] = {'0', ' '};
	size_t		i;

	if (info->map.redzone[y + 1][x + 1] == false)
	{
		ft_putstr_fd("Error: Invalid map: visiting redzone detected\n", 2);
		return (ERROR);
	}
	i = 0;
	while (i < sizeof(valid_land))
	{
		if (precheck
			&& info->map.raw[y]->str[x] == valid_land[i]
			&& info->map.visited[y][x] == false)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

static int	map__dij__visit_neighbor__internal(t_info *info,
		const bool precheck[4], t_coor added[4], t_coor co)
{
	t_result	result;
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		result = map__dij__check_coor(info, precheck[i],
				co.y + _offset(i), co.x + _offset(i + 2));
		if (result == ERROR)
		{
			return (5);
		}
		else if (result == SUCCESS)
		{
			map__coor__add(&added[n++],
				co.y + _offset(i), co.x + _offset(i + 2), '0');
		}
		i++;
	}
	return (n);
}

static int	map__dij__visit_neighbor(t_info *info, t_coor co, t_coor added[4])
{
	const bool	precheck[4] = {
		co.x > 1,
		co.x + 1 < info->map.raw[co.y]->length,
		co.y > 1 && co.x < info->map.raw[co.y - 1]->length,
		co.y + 1 < info->map.height && co.x < info->map.raw[co.y + 1]->length
	};
	size_t		n;

	n = map__dij__visit_neighbor__internal(info, precheck, added, co);
	if (n != 5)
	{
		map__dij__mark_visited(info, added, n);
	}
	return (n);
}

t_result	map__dij__path__release(t_info *info, t_path *open)
{
	size_t	path_total_n;
	size_t	path_n;
	t_coor	new_visited_path[4];
	t_coor	curr;

	path_total_n = 0;
	while (open->count != 0)
	{
		if (map__dij__path__select(open, &curr) == FAILURE)
		{
			return (FAILURE);
			break ;
		}
		path_n = map__dij__visit_neighbor(info, curr, new_visited_path);
		if (path_n == 5)
		{
			return (ERROR);
			break ;
		}
		map__dij__path__remove(open, curr);
		map__dij__path__add(open, new_visited_path, path_n);
		path_total_n += path_n;
	}
	open->count = path_total_n;
	return (SUCCESS);
}
