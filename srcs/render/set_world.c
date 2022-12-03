/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/12/03 16:18:32 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

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

void	ft_show_sprite(t_world *world)
{
	t_player	*p;
	t_sprite	*s;
	t_draw		dr_x;
	t_draw		dr_y;
	size_t		i;

	i = 0;
	p = &world->player;
	while (i < 1/*world->spr_cnt*/)
	{
		s = &world->spr[world->spr[i].order];
		s->pos.x = s->coor.x - p->pos.x;
		s->pos.y = s->coor.y - p->pos.y;
		printf("p: %f %f\n", p->pos.x, p->pos.y);
		printf("s: %f %f\n", s->pos.x, s->pos.y);
		s->idet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
		// printf("%f \n", s->idet);
		s->tr.x = s->idet * (p->dir.y * s->pos.x - p->dir.x * s->pos.y);
		s->tr.y = s->idet * (-p->plane.y * s->pos.x + p->plane.x * s->pos.y);
		// printf("%f %f\n", s->coor.x,s->coor.y);
		printf("tr: %f %f\n", s->tr.x, s->tr.y);

		s->screen_x = (int)((WIN_W / 2) * (1.0 + s->tr.x / s->tr.y));

		s->u_div = 1.0;
		s->v_div = 1.0;
		s->v_move = 0.0;
		s->v_move_screen = (int)(s->v_move / s->tr.y);

		s->h = (int)fabs((WIN_H / s->tr.y) / s->v_div);
		dr_y.start = -s->h / 2 + WIN_H / 2 + s->v_move_screen;
		if (dr_y.start < 0)
			dr_y.start = 0;
		dr_y.end = s->h / 2 + WIN_H / 2 + s->v_move_screen;
		if (dr_y.end >= WIN_H)
			dr_y.end = WIN_H;

		s->w = (int)fabs((WIN_H / s->tr.y) / s->u_div);
		dr_x.start = -s->w / 2 + s->screen_x;
		if (dr_x.start < 0)
			dr_x.start = 0;
		dr_x.end = s->w / 2 + s->screen_x;
		if (dr_x.end >= WIN_W)
			dr_x.end = WIN_W;
		printf("h, w; %d %d\nscreen_x: %d\n", s->h, s->w, s->screen_x);
		printf("x: %d %d\n", dr_x.start, dr_x.end);
		printf("y: %d %d\n", dr_y.start, dr_y.end);
		for (int stripe = dr_x.start; stripe < dr_x.end; stripe++)
		{
			int	texX = (int)((256 * (stripe - (-s->w / 2 + s->screen_x)) * world->tmlx->timg_spr_tex->w / s->w) / 256);
			if (s->tr.y >= 0 && s->tr.y < world->z_buf[stripe])
			{
				//printf("z_buf: %f\n", world->z_buf[stripe]);
				for (int y = dr_y.start; y < dr_y.end; y++)
				{
					int	d = (y - s->v_move_screen) * 256 - WIN_H * 128 + s->h * 128;
					int	texY = ((d * world->tmlx->timg_wall_tex->h) /  s->h) / 256;
					int	color = s->tex[0][world->tmlx->timg_spr_tex->w * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						world->screen_buf[y][stripe] = color;
				}
			}
		}
		i++;
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
	if (world->re)
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
	if (info->core.world.spr != NULL)
	{
		ft_show_sprite(world);
	}
}
