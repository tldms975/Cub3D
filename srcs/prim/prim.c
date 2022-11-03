/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:48:34 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/03 21:02:27 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "prim.h"
#include <stdio.h>
#define INITIAL_SIZE 0x400

void	heap_sort_vertex(t_graph *target, size_t size);
bool	is_vertex(t_info *info, size_t x, size_t y)
{
	const bool	lower_x_precheck = x > 1;
	const bool	upper_x_precheck = x + 1 < info->map.raw[y]->length;
	const bool	lower_y_precheck = (y > 1 && x < info->map.raw[y - 1]->length);
	const bool	upper_y_precheck = (y + 1 < info->map.height
			&& x < info->map.raw[y + 1]->length);

	if (info->map.raw[y]->str[x] == '1')
	{
		if ((lower_y_precheck && info->map.raw[y - 1]->str[x] == '1')
			|| (upper_y_precheck && info->map.raw[y + 1]->str[x] == '1'))
		{
			if ((lower_x_precheck && info->map.raw[y]->str[x - 1] == '1')
				|| (upper_x_precheck && info->map.raw[y]->str[x + 1] == '1'))
			{
				return (true);
			}
		}
	}
	return (false);
}

void	add_vertex(t_graph *g, size_t x, size_t y)
{
	g->vertex_set = ft_realloc(g->vertex_set,
			sizeof(t_vertex) * (g->vertex_count + 1),
			g->vertex_capacity, &g->vertex_capacity);
	g->vertex_set[g->vertex_count].x = x;
	g->vertex_set[g->vertex_count].y = y;
}

t_result	init_vertex(t_info *info, t_graph *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	g->vertex_set = malloc_safe((g->vertex_capacity));
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (is_vertex(info, x, y))
			{
				add_vertex(g, x, y);
				g->vertex_count++;
			}
			x++;
		}
		y++;
	}
	// printf("vertex count : %lu\n", g->vertex_count); TODO -- delete
	return (SUCCESS);
}

t_result	prim(t_info *info)
{
	t_graph	g;

	g.vertex_capacity = INITIAL_SIZE;
	g.vertex_count = 0;
	init_vertex(info, &g);
	connect_vertex(&g);
	return (SUCCESS);
}
