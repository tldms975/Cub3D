/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/16 01:21:15 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
extern int map[MAP_W][MAP_H];

void	ft_init_buf(int (*buf)[WIN_H][WIN_W])
{
	int	w;
	int	h;

	w = 0;
	while (w < WIN_H)
	{
		h = 0;
		while (h < WIN_W)
		{
			(*buf)[w][h] = 0;
			h++;
		}
		w++;
	}
}

void	ft_init_mlx(t_mlx *tmlx, t_world *world)
{
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_W, WIN_H, "cub3d");
	tmlx->timg.img = mlx_new_image(tmlx->mlx, WIN_W, WIN_H);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);
	//
	// world->mini.img = mlx_new_image(tmlx->mlx, MINI_W, MINI_H);
	// world->mini.data =  (int *)mlx_get_data_addr(world->mini.img, \
	// &world->mini.bpp, &world->mini.line_len, &world->mini.endian);
	//
	world->tmlx = tmlx;
}

void	ft_set_player_cardinal(t_player *p)
{
	double	degree;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	degree = 0.0;
	if (p->cardinal == 'N')
		return ;
	else if (p->cardinal == 'W')
		degree = 1.5;
	else if (p->cardinal == 'S')
		degree = 3.0;
	else if (p->cardinal == 'E')
		degree = 4.5;
	p->dir.x = p->dir.x * cos(-degree) - p->dir.y * sin(-degree);
	p->dir.y = old_dir_x * sin(-degree) + p->dir.y * cos(-degree);
	p->plane.x = p->plane.x * cos(-degree) - p->plane.y * sin(-degree);
	p->plane.y = old_plane_x * sin(-degree) + p->plane.y * cos(-degree);
	return ;
}

void	ft_init_player(t_player *p)
{
	p->pos.x =22.5;
	p->pos.y =22.5;
	p->dir.x = -0.9543;
	p->dir.y = 0.0;
	p->plane.x = 0.0;
	p->plane.y = 0.66;
	p->move_speed = 0.05;
	p->rot_speed = 0.08;
	ft_set_player_cardinal(p);
}

int	ft_init_render(t_mlx *tmlx, t_world *world)
{
	ft_init_mlx(tmlx, world);
	ft_init_buf(&world->screen_buf);
	world->texture = ft_init_texture();
	tmp_load_texture(world);
	ft_init_player(&world->player);
	ft_set_minimap(world);
	//parse
	world->rgb.floor = 0x336600;
	world->rgb.ceiling = 0x0099FF;
	// world->map = map;
	//
	world->re = 0;
	return (1);
}
