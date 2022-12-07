/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/12/07 16:05:41 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include "sprite.h"

void	ft_fill_buf(t_world *world, t_raycast *rc, t_texture *tex, size_t x)
{
	t_draw	dr;
	size_t	y;

	dr.line_h = (int)(world->screen_h / rc->d);
	dr.start = (-dr.line_h / 2) + (world->screen_h / 2);
	dr.end = (dr.line_h / 2) + (world->screen_h / 2);
	if (dr.start < 0)
		dr.start = 0;
	if (dr.end >= (int)world->screen_h)
		dr.end = (int)world->screen_h - 1;
	if (world->wall_tex[tex->type] != NULL)
	{
		ft_wear_texture(world, rc, tex, &dr);
	}
	y = dr.start;
	while ((int)y < dr.end)
	{
		world->screen_buf[y][x] = ft_get_color(world, rc, tex, &dr);
		y++;
	}
}

void	ft_world_on_screen(t_info *info, t_mlx *tmlx)
{
	size_t	w;
	size_t	h;

	h = 0;
	while (h < info->core.world.screen_h)
	{
		w = 0;
		while (w < info->core.world.screen_w)
		{
			tmlx->timg_main.data[(h * info->core.world.screen_w) + w] \
			= info->core.world.screen_buf[h][w];
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg_main.img, 0, 0);
}

void	ft_init_screen_buf(t_info *info)
{
	size_t	w;
	size_t	h;

	h = 0;
	while (h < info->core.world.screen_h)
	{
		w = 0;
		while (w < info->core.world.screen_w)
		{
			info->core.world.screen_buf[h][w] = 0;
			w++;
		}
		h++;
	}
}

void	ft_set_world(t_info *info)
{
	t_raycast	rc;
	t_texture	tex;
	t_world		*world;
	size_t		x;

	world = &info->core.world;
	x = 0;
	ft_init_screen_buf(info);
	ft_background(world);
	while (x < info->core.world.screen_w)
	{
		ft_init_rc(world, &rc, x);
		ft_step_dir(&world->player, &rc);
		ft_check_hit(world, &world->player, &rc, &tex);
		ft_fill_buf(world, &rc, &tex, x);
		world->z_buf[x] = rc.d;
		x++;
	}
	if (info->core.world.spr)
	{
		ft_show_sprite(world);
	}
}
