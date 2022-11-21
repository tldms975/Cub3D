/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/22 00:38:59 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

void	ft_player_on_minimap(t_info *info, t_player *p)
{
	const int	player_color = 0xFF66FF;
	int			size;
	int			i;
	int			j;

	size = info->core.world.minimap_w / info->map.width;
	i = -size / 2;
	while (i < size / 2)
	{
		j = -size / 2;
		while (j < size / 2)
		{
			info->core.world.tmlx->timg_mini.data[(int)((p->pos.y * size + j) * (info->core.world.minimap_w)) + (int)(p->pos.x * size) + i] = player_color;
			j++;
		}
		i++;
	}
}

void	ft_minimap_on_screen(t_info *info, t_mlx *tmlx)
{
	size_t	w;
	size_t	h;

	h = 0;
	w = 0;
	while (h < info->core.world.minimap_h)
	{
		w = 0;
		while (w < (info->core.world.minimap_w))
		{
			info->core.world.tmlx->timg_mini.data[h * (info->core.world.minimap_w) + w] = info->core.world.minimap_buf[h][w];
			w++;
		}
		h++;
	}
	ft_player_on_minimap(info, &info->core.world.player);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, info->core.world.tmlx->timg_mini.img, 5, 5);
}

void	ft_fill_miniimap_block(t_info *info, int y, int x, int color)
{
	int	wsize;
	int	hsize;
	int	i;
	int	j;

	wsize = info->core.world.minimap_w / info->map.width;
	hsize = info->core.world.minimap_h / info->map.height;
	i = 0;
	while (i < hsize)
	{
		j = 0;
		while (j < wsize)
		{
			info->core.world.minimap_buf[y * hsize + i][x * wsize + j] = color;
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_info *info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.width)
		{
			if (info->core.world.map[y][x] == '1')
				ft_fill_miniimap_block(info, y, x, 0x996633);
			else if (info->core.world.map[y][x] == ' ')
				ft_fill_miniimap_block(info, y, x, 0x000000);
			else
				ft_fill_miniimap_block(info, y, x, 0x9966FF);
			x++;
		}
		y++;
	}
}
