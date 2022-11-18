/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/18 15:08:47 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_player_on_minimap(t_world *world, t_player *p)
{
	const int	player_color = 0xFF66FF;
	int			size;
	int			i;
	int			j;

	size = MINI_W / MAP_W;
	i = -size / 2;
	while (i < size / 2)
	{
		j = -size / 2;
		while (j < size / 2)
		{
			world->minimap.data[(int)(p->pos.y * size + j) * (MINI_W + T) \
			+ (int)(p->pos.x * size + i)] = player_color;
			j++;
		}
		i++;
	}
}
void	ft_minimap_on_screen(t_world *world, t_mlx *tmlx)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	while (h < MINI_H)
	{
		w = 0;
		while (w < (MINI_W + T))
		{
			world->minimap.data[h * (MINI_W + T) + w] = world->minimap_buf[h][w];
			w++;
		}
		h++;
	}
	ft_player_on_minimap(world, &world->player);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, world->minimap.img, 5, 5);
}

void	ft_fill_map_block(t_world *world, int w, int h, int color)
{
	int	size;
	int	i;
	int	j;

	size = MINI_W / MAP_W;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			world->minimap_buf[h * size + i][w * size + j] = color;
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_world *world)
{
	int	w;
	int	h;

	(void)world;
	w = 0;
	while (w < MAP_W)
	{
		h = 0;
		while (h < MAP_H)
		{
			if (world->map[w][h] == '0')
				ft_fill_map_block(world, w, h, 0x9966FF);
			else if (world->map[w][h] == ' ')
				ft_fill_map_block(world, w, h, 0x000000);
			else
				ft_fill_map_block(world, w, h, 0x996633);
			h++;
		}
		w++;
	}
}
