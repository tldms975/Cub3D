/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/25 03:51:33 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "render.h"
#include "types/t_world.h"
#include <stdio.h>
#include <math.h>

void	ft_player_on_minimap(t_info *info, t_player *p)
{
	const int	player_color = 0xFF66FF;
	int			wsize;
	int			hsize;
	int			i;
	int			j;

	wsize = ceil((double)info->core.world.minimap_w / info->map.width);
	hsize = ceil((double)info->core.world.minimap_h / info->map.height);
	i = 0;
	while (i < ceil((double)hsize / 2))
	{
		j = 0;
		while (j < ceil((double)wsize / 2))
		{
			info->core.world.tmlx->timg_mini.data \
			[(((int)(p->pos.y * hsize) + i) * (info->core.world.minimap_w)) \
			+ ((int)(p->pos.x * wsize) + j)] \
			= player_color;
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
			info->core.world.tmlx->timg_mini.data[h * \
			(info->core.world.minimap_w) + w] \
			= info->core.world.minimap_buf[h][w];
			w++;
		}
		h++;
	}
	ft_player_on_minimap(info, &info->core.world.player);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, \
	info->core.world.tmlx->timg_mini.img, 5, 5);
}

void	ft_fill_miniimap_block(t_info *info, int y, int x, int color)
{
	int	wsize;
	int	hsize;
	int	i;
	int	j;

	wsize = ceil((double)info->core.world.minimap_w / info->map.width);
	hsize = ceil((double)info->core.world.minimap_h / info->map.height);
	i = 0;
	while (i < hsize)
	{
		j = 0;
		while (j < wsize)
		{
			info->core.world.minimap_buf[(int)(y * hsize) + i] \
			[(int)(x * wsize) + j] = color;
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_info *info)
{
	size_t	x;
	size_t	y;
	t_minimap_color	color;

	color.bg = create_trgb(255, 0, 0, 0);
	color.fg = create_trgb(100, 90, 102, 70);
	color.wl = create_trgb(100, 198, 210, 202);
	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.width)
		{
			if (info->core.world.map[y][x] == '1')
				ft_fill_miniimap_block(info, y, x, color.fg);
			else if (info->core.world.map[y][x] == ' '
					|| info->core.world.map[y][x] == '\n')
				ft_fill_miniimap_block(info, y, x, color.bg);
			else
				ft_fill_miniimap_block(info, y, x, color.wl);
			x++;
		}
		y++;
	}
}
