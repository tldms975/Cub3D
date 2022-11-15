
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

extern int map[MAP_W][MAP_H];

void	ft_background(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			world->screen_buf[y][x] = world->rgb.ceiling;
			world->screen_buf[WIN_H - y - 1][x] = world->rgb.floor;
			x++;
		}
		y++;
	}
}

void	ft_init_rc(t_player *p, t_raycast *rc, int x)
{
	rc->cam_x = 2 * x / (double)WIN_W - 1;
	rc->ray.x = p->dir.x + p->plane.x * rc->cam_x;
	rc->ray.y = p->dir.y + p->plane.y * rc->cam_x;
	rc->block.x = (int)p->pos.x;
	rc->block.y = (int)p->pos.y;
	rc->delta.x = fabs(1 / rc->ray.x);
	rc->delta.y = fabs(1 / rc->ray.y);
}

void	ft_step_dir(t_player *p,t_raycast *rc)
{
	if (rc->ray.x < 0)
	{
		rc->step.x = -1;
		rc->side.x = (p->pos.x - rc->block.x) * rc->delta.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side.x = (rc->block.x + 1.0 - p->pos.x) * rc->delta.x;
	}
	if (rc->ray.y < 0)
	{
		rc->step.y = -1;
		rc->side.y = (p->pos.y - rc->block.y) * rc->delta.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side.y = (rc->block.y + 1.0 - p->pos.y) * rc->delta.y;
	}
}

void	ft_check_hit(t_world *world, t_player *p, t_raycast *rc)
{
	int	hit;

	hit = 0;
	(void)world;//for parsed map
	while (hit == 0)
	{
		if (rc->side.x < rc->side.y)
		{
			rc->side.x += rc->delta.x;
			rc->block.x += rc->step.x;
			rc->is_side = 0;
		}
		else
		{
			rc->side.y += rc->delta.y;
			rc->block.y += rc->step.y;
			rc->is_side = 1;
		}
		if (map[rc->block.x][rc->block.y] > 0)
		{
			hit = 1;
		}
	}
	if (rc->is_side == 0)
		rc->d = (rc->block.x - p->pos.x + (1 - rc->step.x) / 2) / rc->ray.x;
	else
		rc->d = (rc->block.y - p->pos.y + (1 - rc->step.y) / 2) / rc->ray.y;
}

int		ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	dr->tex.y = (int)tex->pos & (TEX_H - 1);
	tex->pos += tex->step;
	color = world->texture[tex->type][TEX_H * dr->tex.y + dr->tex.x];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}

void	ft_wear_texture(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	tex->type = map[rc->block.x][rc->block.y] - 1;
	if (rc->is_side == 0)
		tex->wall_x = world->player.pos.y + rc->d * rc->ray.y;
	else
		tex->wall_x = world->player.pos.x + rc->d * rc->ray.x;
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

void	ft_set_world(t_world *world)
{
	t_raycast	rc;
	t_texture	tex;
	int	x;

	x = 0;
	if (world->re)
		ft_init_buf(&world->screen_buf);
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
