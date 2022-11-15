/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__coor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:20:02 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map__coor__add(t_coor *result, size_t y, size_t x, int c)
{
	result->x = x;
	result->y = y;
	result->c = c;
}
