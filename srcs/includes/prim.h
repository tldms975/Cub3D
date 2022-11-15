/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:51:41 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/03 23:13:11 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIM_H
# define PRIM_H

#include <stddef.h>

typedef struct s_vertex
{
	size_t	x;
	size_t	y;
}	t_vertex;

typedef struct s_edge
{
	t_vertex	*a;
	t_vertex	*b;
	int			weight;
}	t_edge;

typedef struct s_graph
{
	t_vertex	*vertex_set;
	t_edge		*edge_set;
	size_t		vertex_count;
	size_t		vertex_capacity;
	size_t		edge_count;
	size_t		edge_capacity;
}	t_graph;

#endif // !PRIM_H
