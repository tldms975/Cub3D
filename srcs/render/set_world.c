
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

int		ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	dr->tex.y = (int)tex->pos & (TEX_H - 1);
	tex->pos += tex->step;
	color = world->texture[tex->type][(int)(TEX_H * dr->tex.y + dr->tex.x)];
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
	dr->tex.x = (int)(tex->wall_x * (double)TEX_W);
	if ((rc->is_side == 0 && rc->ray.x > 0) \
	|| (rc->is_side == 1 && rc->ray.y < 0))
		dr->tex.x = TEX_W - dr->tex.x - 1;
	tex->step = 1.0 * TEX_H / dr->line_h;
	tex->pos = (dr->start - WIN_H / 2 + dr->line_h / 2) * tex->step;
}

void	ft_fill_buf(t_world *world, t_raycast *rc, t_texture *tex, int x)
{
	t_draw	dr;
	int	y;

	dr.line_h = (int)(WIN_H / rc->d);
	dr.start = -dr.line_h / 2 + WIN_H / 2;
	dr.end = dr.line_h / 2 + WIN_H / 2;
	if (dr.start < 0)
		dr.start = 0;
	if (dr.end >= WIN_H)
		dr.end = WIN_H - 1;
	ft_wear_texture(world, rc, tex, &dr);
	y = dr.start;
	while (y < dr.end)
	{
		world->screen_buf[y][x] = ft_get_color(world, rc, tex, &dr);
		world->re = 1;
		y++;
	}
}

void	ft_world_on_screen(t_world *world, t_mlx *tmlx)
{
	int	w;
	int	h;

	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			tmlx->timg.data[h * WIN_W + w] = world->screen_buf[h][w];
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg.img, 0, 0);
}

void	ft_set_world(t_world *world)
{
	t_raycast	rc;
	t_texture	tex;
	int	x;

	x = 0;
	if (world->re)
		ft_init_screen_buf(&world->screen_buf);
	ft_background(world);
	while (x < WIN_W)
	{
		ft_init_rc(&world->player, &rc, x);
		ft_step_dir(&world->player, &rc);
		ft_check_hit(world, &world->player, &rc);
		ft_fill_buf(world, &rc, &tex, x);
		x++;
	}
}
