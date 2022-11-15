/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/15 23:23:21 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
extern int map[MAP_W][MAP_H];

void	ft_set_minimap(t_world *world)
{
	int	w;
	int	h;
	int	size;

	(void)world;
	w = 0;
	while (w < MAP_W)
	{
		h = 0;
		size = 0;
		while (h < MAP_H)
		{
			if (map[w][h])
				world->minimap_buf[w][h] == 0x9966FF;
			else
				world->minimap_buf[w][h] == 0x996633;
			h++;
			size++;
		}
		w++;
	}
}
