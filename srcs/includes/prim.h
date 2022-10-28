/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:51:41 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/29 06:35:15 by hdoo             ###   ########.fr       */
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
	t_vertex	a;
	t_vertex	b;
	int			weight;
}	t_edge;

typedef struct s_graph
{
	t_vertex *vertex_set;
	t_edge *edge_set;
}	t_graph;

#endif // !PRIM_H
