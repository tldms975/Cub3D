/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__dij_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:29:08 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map__dij__mark_visited(t_info *info, t_coor visited[4],	size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		info->map.visited[visited[i].y][visited[i].x] = true;
		i++;
	}
}

static void	map__dij__path__coor__add(t_path *open, int y, int x, int c)
{
	size_t	i;

	i = 0;
	while (i < open->capacity / sizeof(t_coor))
	{
		if (open->path[i].c == 0 || open->path[i].c == -1)
		{
			open->path[i].c = c;
			open->path[i].x = x;
			open->path[i].y = y;
			break ;
		}
		i++;
	}
}

size_t	map__dij__path__add(t_path *open, t_coor *new_coor, size_t new_size)
{
	size_t	i;

	if (open == NULL)
	{
		ft_putstr_fd("Error: add_open_path: open_path is NULL", 2);
	}
	i = 0;
	while (i < new_size)
	{
		if (open->count * sizeof(t_coor) >= open->capacity)
		{
			open->capacity *= 2;
			open->path
				= ft_realloc(open->path, sizeof(t_coor) * open->count,
					open->capacity, &open->capacity);
		}
		map__dij__path__coor__add(open,
			new_coor[i].y, new_coor[i].x, new_coor[i].c);
		i++;
	}
	return (i);
}

void	map__dij__path__remove(t_path *open, t_coor curr)
{
	size_t	i;

	i = 0;
	while (i < open->count)
	{
		if (open->path[i].x == curr.x
			&& open->path[i].y == curr.y)
		{
			open->path[i].c = -1;
			return ;
		}
		i++;
	}
	open->count--;
}

t_result	map__dij__path__select(t_path *open, t_coor *curr)
{
	size_t	i;

	i = 0;
	while (i < open->capacity / sizeof(t_coor))
	{
		if (open->path[i].c != -1 && open->path[i].c != 0)
		{
			*curr = open->path[i];
			return (SUCCESS);
		}
		i++;
	}
	return (FAILURE);
}
