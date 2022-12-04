/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__dij_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 17:26:12 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"


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

t_result	map__dij__path__add(t_path *open, t_coor *new_coor, size_t new_size)
{
	size_t	i;

	if (open == NULL)
	{
		ft_putstr_fd("Error: add_open_path: open_path is NULL", 2);
		return (ERROR);
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
	return (SUCCESS);
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
			open->path[i].c = -1;
			open->count--;
			return (SUCCESS);
		}
		i++;
	}
	return (FAILURE);
}
