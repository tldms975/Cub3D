/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 15:07:34 by yui              ###   ########.fr       */
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
	if (world->wall_tex[tex->type] != NULL)
	{
		ft_wear_texture(world, rc, tex, &dr);
	}
	y = dr.start;
	while ((int)y < dr.end)
	{
		world->screen_buf[y][x] = ft_get_color(world, rc, tex, &dr);
		world->re = 1;//?
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

void	ft_draw_sprite(t_sprite *s, t_world *world)
{
	t_ivec	line;
	t_ivec	tex;
	int		d;
	int		color;

	line.x = s->dr_x.start;
	while (line.x < s->dr_x.end)
	{
		tex.x = (int)((256 * (line.x - (-s->w / 2 + s->screen_x)) \
		* world->tmlx->timg_spr_tex[0].w / s->w) / 256);
		if (s->tr.y >= 0 && s->tr.y < world->z_buf[line.x])
		{
			line.y = s->dr_y.start;
			while (line.y < s->dr_y.end)
			{
				d = (line.y - s->v_move_screen) * 256 - WIN_H * 128 + s->h * 128;
				tex.y = ((d * world->tmlx->timg_spr_tex[0].h) / s->h) / 256;
				color = world->spr_tex[0][world->tmlx->timg_spr_tex[0].w * tex.y + tex.x];
				if ((color & 0x00FFFFFF) != 0)
					world->screen_buf[line.y][line.x] = color;
				line.y++;
			}
		}
		line.x++;
	}
}

void	ft_init_sprite(t_sprite *s, t_player *p)
{
	s->pos.x = s->coor.x - p->pos.x;
	s->pos.y = s->coor.y - p->pos.y;
	s->idet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	s->tr.x = s->idet * (p->dir.y * s->pos.x - p->dir.x * s->pos.y);
	s->tr.y = s->idet * (-p->plane.y * s->pos.x + p->plane.x * s->pos.y);
	s->screen_x = (int)((WIN_W / 2) * (1.0 + s->tr.x / s->tr.y));
	s->u_div = 1;
	s->v_div = 1;
	s->v_move = 0;
	s->v_move_screen = (int)(s->v_move / s->tr.y);
	s->h = (int)fabs((WIN_H / s->tr.y) / s->v_div);
	s->dr_y.start = -s->h / 2 + WIN_H / 2 + s->v_move_screen;
	s->dr_y.end = s->h / 2 + WIN_H / 2 + s->v_move_screen;
	if (s->dr_y.start < 0)
		s->dr_y.start = 0;
	if (s->dr_y.end >= WIN_H)
		s->dr_y.end = WIN_H;
	s->w = (int)fabs((WIN_H / s->tr.y) / s->u_div);
	s->dr_x.start = -s->w / 2 + s->screen_x;
	s->dr_x.end = s->w / 2 + s->screen_x;
	if (s->dr_x.start < 0)
		s->dr_x.start = 0;
	if (s->dr_x.end >= WIN_W)
		s->dr_x.end = WIN_W;
}

typedef struct s_spr_arr
{
	double	d;
	int		id;
}		t_spr_arr;

void	ft_swap(t_spr_arr *a, t_spr_arr *b)
{
	t_spr_arr	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_get_sprite_order(t_sprite *s, int n)
{
	t_spr_arr	*arr;
	int		*ret;
	int		i;
	int		j;

	i = 0;
	ret = malloc_safe(sizeof(int) * n);
	if (n == 1)
	{
		ret[i] = 0;
		return (ret);
	}
	arr = malloc_safe(sizeof(t_spr_arr) * n);
	while (i < n)
	{
		arr[i].id = i;
		arr[i].d = pow(s[i].pos.x, 2) + pow(s[i].pos.y, 2);
		i++;
	}
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i].d < arr[j].d)
			{
				ft_swap(&arr[i], &arr[j]);
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		ret[i] = arr[i].id;
		i++;
	}
	free(arr);
	return (ret);
}

void	ft_show_sprite(t_world *world)
{
	size_t		i;
	int			*order;

	i = 0;
	while (i < world->spr_cnt)
	{
		ft_init_sprite(&world->spr[i], &world->player);
		i++;
	}
	order = ft_get_sprite_order(world->spr, world->spr_cnt);
	i = 0;
	while (i < world->spr_cnt)
	{
		ft_draw_sprite(&world->spr[order[i]], world);
		i++;
	}
	free(order);
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
	if (info->core.world.spr)
	{
		ft_show_sprite(world);
	}
}
