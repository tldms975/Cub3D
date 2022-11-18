/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:22 by sielee            #+#    #+#             */
/*   Updated: 2022/11/19 05:35:34 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_player_on_minimap(t_info *info, t_player *p)
{
	const int	player_color = 0xFF66FF;
	int			size;
	int			i;
	int			j;

	size = MINI_W / info->core.world.map_w;
	i = -size / 2;
	while (i < size / 2)
	{
		j = -size / 2;
		while (j < size / 2)
		{
			info->core.world.minimap.data[(int)(p->pos.y * size + j) * (MINI_W + T) \
			+ (int)(p->pos.x * size + i)] = player_color;
			j++;
		}
		i++;
	}
}
void	ft_minimap_on_screen(t_info *info, t_mlx *tmlx)
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
			info->core.world.minimap.data[h * (MINI_W + T) + w] = info->core.world.minimap_buf[h][w];
			w++;
		}
		h++;
	}
	ft_player_on_minimap(info, &info->core.world.player);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, info->core.world.minimap.img, 5, 5);
}

void	ft_fill_map_block(t_info *info, int w, int h, int color)
{
	int	size;
	int	i;
	int	j;

	size = MINI_W / info->core.world.map_w;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			info->core.world.minimap_buf[h * size + i][w * size + j] = color;
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_info *info)
{
	size_t	w;
	size_t	h;

	w = 0;
	while (w < info->map.height)
	{
		h = 0;
		while (h < info->map.raw[w]->length)
		{
			if (info->core.world.map[w]->str[h] == '0')
				ft_fill_map_block(info, w, h, 0x9966FF);
			else if (info->core.world.map[w]->str[h] == ' ')
				ft_fill_map_block(info, w, h, 0x000000);
			else
				ft_fill_map_block(info, w, h, 0x996633);
			h++;
		}
		w++;
	}
}
