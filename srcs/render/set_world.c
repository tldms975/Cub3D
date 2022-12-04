/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/12/04 02:39:05 by sielee           ###   ########seoul.kr  */
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

void	ft_draw_sprite(t_sprite *s, t_world *world, t_draw *dr_x, t_draw *dr_y)
{
	t_ivec	line;
	t_ivec	tex;
	int		d;
	int		color;

	line.x = dr_x->start;
	while (line.x < dr_x->end)
	{
		tex.x = (int)((256 * (line.x - (-s->w / 2 + s->screen_x)) \
		* world->tmlx->timg_spr_tex[0].w / s->w) / 256);
		if (s->tr.y >= 0 && s->tr.y < world->z_buf[line.x])
		{
			line.y = dr_y->start;
			while (line.y < dr_y->end)
			{
				d = (line.y - s->v_move_screen) * 256 - WIN_H * 128 + s->h * 128;
				tex.y = ((d * world->tmlx->timg_spr_tex[0].h) / s->h) / 25;
				color = s->tex[0][world->tmlx->timg_spr_tex[0].w * tex.y + tex.x];
				if ((color & 0x00FFFFFF) != 0)
					world->screen_buf[line.y][line.x] = color;
				line.y++;
			}
		}
		line.x++;
	}
}

void	ft_init_sprite(t_sprite *s, t_player *p, t_draw *dr_x, t_draw *dr_y)
{
	s->pos.x = s->coor.x - p->pos.x;
	s->pos.y = s->coor.y - p->pos.y;
	s->idet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	s->tr.x = s->idet * (p->dir.y * s->pos.x - p->dir.x * s->pos.y);
	s->tr.y = s->idet * (-p->plane.y * s->pos.x + p->plane.x * s->pos.y);
	s->screen_x = (int)((WIN_W / 2) * (1.0 + s->tr.x / s->tr.y));
	s->u_div = 10;
	s->v_div = 2;
	s->v_move = WIN_H;
	s->v_move_screen = (int)(s->v_move / s->tr.y);
	s->h = (int)fabs((WIN_H / s->tr.y) / s->v_div);
	dr_y->start = -s->h / 2 + WIN_H / 2 + s->v_move_screen;
	dr_y->end = s->h / 2 + WIN_H / 2 + s->v_move_screen;
	if (dr_y->start < 0)
		dr_y->start = 0;
	if (dr_y->end >= WIN_H)
		dr_y->end = WIN_H;
	s->w = (int)fabs((WIN_H / s->tr.y) / s->u_div);
	dr_x->start = -s->w / 2 + s->screen_x;
	dr_x->end = s->w / 2 + s->screen_x;
	if (dr_x->start < 0)
		dr_x->start = 0;
	if (dr_x->end >= WIN_W)
		dr_x->end = WIN_W;
}

int	*ft_get_sprite_order(t_sprite *s, int n)
{
	double	*d;
	int		*ret;
	int		i;
	int		j;

	d = malloc_safe(sizeof(int) * n);
	ret = malloc_safe(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		d[i] = pow(s[i].pos.x, 2) + pow(s[i].pos.y, 2);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (d[i] > d[j])
				ret[i] = s[i].id;
			else
				ret[i] = s[j].id;
			j++;
		}
		i++;
	}
	free(d);
	return (ret);
}

void	ft_show_sprite(t_world *world)
{
	t_draw		dr_x;
	t_draw		dr_y;
	size_t		i;
	int			order[2];

	i = 0;
	while (i < world->spr_cnt)
	{
		ft_init_sprite(&world->spr[i], &world->player, &dr_x, &dr_y);
		i++;
	}
	//order = ft_get_sprite_order(world->spr, world->spr_cnt);
	order[0] = 0;
	order[1] = 0;
	i = 0;
	while (i < world->spr_cnt)
	{
		ft_draw_sprite(&world->spr[order[i]], world, &dr_x, &dr_y);//가장 멀리있는거 우선순위
		i++;
	}
	//free(order);
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
