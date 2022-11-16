/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/16 15:20:17 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
extern int map[MAP_W][MAP_H];
#include <stdio.h>//tmp
void	ft_player_on_minimap(t_world *world, t_player *p)
{
	const int	player_color = 0xFF66FF;
	int			size;
	int			start;
	int			end;

	size = WIN_H / MINI_H;
	start = size / 3;
	end = size * 2 / 3;
	while (start != end)
	{
		start = size / 3;
		world->minimap.data[(int)(p->pos.y + start) * MINI_W \
		+ (int)p->pos.x + start] = player_color;
		start++;
	}
}

void	ft_minimap_on_screen(t_world *world, t_mlx *tmlx)
{
	int	w;
	int	h;

	h = 0;
	while (h < MINI_H)
	{
		w = 0;
		while (w < MINI_W)
		{
			world->minimap.data[h * MINI_W + w] = world->minimap_buf[h][w];
			w++;
		}
		h++;
	}
	ft_player_on_minimap(world, &world->player);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, world->minimap.img, 0, 0);
}

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
		while (h < MAP_H)
		{
			size = WIN_H / MINI_H;
			while (size != 0)
			{
				if (map[w][h] == 0)
					world->minimap_buf[h + size][w + size] = 0x9966FF;
				else
					world->minimap_buf[h + size][w + size] = 0x996633;
				size--;
			}
			h++;
		}
		w++;
	}
}
