
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/10/29 23:40:41 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include <stdio.h>

int		ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	dr->tex.y = (int)tex->pos & (world->tmlx->timg_texture[tex->type].h - 1);
	tex->pos += tex->step;
	color = world->texture[tex->type][(int)(world->tmlx->timg_texture[tex->type].h * dr->tex.y + dr->tex.x)];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}

void	ft_wear_texture(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	if (rc->is_side == 0)
	{
		tex->wall_x = world->player.pos.y + rc->d * rc->ray.y;
		tex->type = NO;
		if (rc->step.x > 0)
			tex->type = SO;
	}
	else
	{
		tex->wall_x = world->player.pos.x + rc->d * rc->ray.x;
		tex->type = WE;
		if (rc->step.y > 0)
			tex->type = EA;
	}
	tex->wall_x -= floor(tex->wall_x);
	dr->tex.x = (int)(tex->wall_x * world->tmlx->timg_texture[tex->type].w);
	if ((rc->is_side == 0 && rc->ray.x > 0) \
	|| (rc->is_side == 1 && rc->ray.y < 0))
		dr->tex.x = world->tmlx->timg_texture[tex->type].w - dr->tex.x - 1;
	tex->step = 1.0 * world->tmlx->timg_texture[tex->type].h  / dr->line_h;
	tex->pos = (dr->start - world->screen_h / (double)(2 + dr->line_h) / 2) * tex->step;
}

void	ft_fill_buf(t_world *world, t_raycast *rc, t_texture *tex, int x)
{
	t_draw	dr;
	size_t	y;

	dr.line_h = (int)(world->screen_h / rc->d);
	dr.start = -dr.line_h / 2 + world->screen_h / 2;
	dr.end = dr.line_h / 2 + world->screen_h / 2;
	if (dr.start < 0)
		dr.start = 0;
	if (dr.end >= (int)world->screen_h)
		dr.end = (int)world->screen_h - 1;
	ft_wear_texture(world, rc, tex, &dr);
	y = dr.start;
	while ((int)y < dr.end)
	{
		world->screen_buf[y][x] = ft_get_color(world, rc, tex, &dr);
		world->re = 1;
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
			tmlx->timg_main.data[h * info->core.world.screen_w + w] = info->core.world.screen_buf[h][w];
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
	size_t		y;

	world = &info->core.world;
	y = 0;
	if (world->re)
		ft_init_screen_buf(info);
	ft_background(world);
	while (y < info->core.world.screen_h)
	{
		ft_init_rc(world, &rc, y);
		ft_step_dir(&world->player, &rc);
		ft_check_hit(world, &world->player, &rc);
		ft_fill_buf(world, &rc, &tex, y);
		y++;
	}
}
