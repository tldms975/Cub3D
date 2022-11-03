/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_sort_env_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:21:40 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/03 20:54:04 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prim.h"
#include <unistd.h>
#include <stdio.h>

static void	swap_vertex(t_graph *g, int a, int b)
{
	t_vertex	temp;

	temp = g->vertex_set[a];
	g->vertex_set[a] = g->vertex_set[b];
	g->vertex_set[b] = temp;
}

static void	heapify_max(t_graph *g, size_t parent, size_t size)
{
	size_t	left;
	size_t	right;
	size_t	largest;

	largest = parent;
	left = (parent * 2) + 1;
	right = (parent * 2) + 2;
	if (left < size && g->vertex_set[left].y > g->vertex_set[largest].y )
		largest = left;
	if (right < size && g->vertex_set[right].y > g->vertex_set[largest].y )
		largest = right;
	if (parent != largest)
	{
		swap_vertex(g, parent, largest);
		heapify_max(g, largest, size);
	}
}

static void	build_max_heap(t_graph *target, size_t size)
{
	size_t	mid;

	mid = size / 2;
	while (mid > 0)
	{
		heapify_max(target, mid, size);
		mid--;
	}
	heapify_max(target, mid, size);
}

void	heap_sort_vertex(t_graph *target, size_t size)
{
	size_t	end;

	if (size <= 0)
		return ;
	build_max_heap(target, size);
	end = size - 1;
	while (end > 0)
	{
		swap_vertex(target, 0, end);
		heapify_max(target, 0, end);
		end--;
	}
	return ;
}
