/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 16:45:40 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "render.h"
#include "types/t_world.h"
#include <stdio.h>
#include <math.h>
#include "minimap.h"

void	ft_player_on_minimap(t_info *info, t_player *p)
{
	const int	player_color = 0xFF66FF;
	t_world		*w;
	int			i;
	int			j;

	w = &info->core.world;
	i = 0;
	while (i < (double)w->b_size_h / 2)
	{
		j = 0;
		while (j < (double)w->b_size_w / 2)
		{
			w->tmlx->timg_mini.data
			[(((int)(p->pos.y * w->b_size_h) + i)
					* (info->core.world.minimap_w))
				+ ((int)(p->pos.x * w->b_size_w) + j)]
				= player_color;
			j++;
		}
		i++;
	}
}

void	ft_fill_miniimap_block(t_info *info, int y, int x, int color)
{
	t_world	*w;
	size_t	i;
	size_t	j;

	w = &info->core.world;
	w->b_size_w = ceil((double)info->core.world.minimap_w / info->map.width);
	w->b_size_h = ceil((double)info->core.world.minimap_h / info->map.height);
	i = 0;
	while (i < w->b_size_h)
	{
		j = 0;
		while (j < w->b_size_w)
		{
			w->minimap_buf[(int)(y * w->b_size_h) + i] \
			[(int)(x * w->b_size_w) + j] = color;
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

void	ft_set_minimap(t_info *info)
{
	size_t			x;
	size_t			y;
	t_minimap_color	color;

	set_minimap_color(&color);
	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.width)
		{
			put_color(info, x, y, color);
			x++;
		}
		y++;
	}
}
