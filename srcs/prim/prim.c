/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:48:34 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/29 06:01:14 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "prim.h"

t_result	init_graph(t_info *info, t_graph *g)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < info->map.raw_data[y]->length)


}

t_result	prim(t_info *info)
{
	t_graph g;

	init_graph(info, &g);

	return (SUCCESS);
}

