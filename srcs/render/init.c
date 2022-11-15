/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/15 18:23:13 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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

void	tmp_load_image(t_mlx *tmlx, int *texture, char *path, t_image *timg)
{
	int	y;
	int	x;

	y = 0;
	timg->img = mlx_xpm_file_to_image(tmlx->mlx, path, &timg->w, &timg->h);
	timg->data = (int *)mlx_get_data_addr(timg->img, &timg->bpp, &timg->line_len, &timg->endian);
	while (y < timg->h)
	{
		x = 0;
		while (x < timg->w)
		{
			texture[timg->w * y + x] = timg->data[timg->w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(tmlx->mlx, timg->img);
}

void	tmp_load_texture(t_world *world)
{
	t_image	timg;

	tmp_load_image(world->tmlx, world->texture[0], "textures/eagle.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[1], "textures/redbrick.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[2], "textures/purplestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[3], "textures/greystone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[4], "textures/bluestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[5], "textures/mossy.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[6], "textures/wood.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[7], "textures/colorstone.xpm", &timg);
}

void	ft_init_mlx(t_mlx *tmlx, t_world *world)
{
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_W, WIN_H, "cub3d");
	tmlx->timg.img = mlx_new_image(tmlx->mlx, WIN_W, WIN_H);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);
	//
	world->mini.img = mlx_new_image(tmlx->mlx, MINI_W, MINI_H);
	world->mini.data =  (int *)mlx_get_data_addr(world->mini.img, \
	&world->mini.bpp, &world->mini.line_len, &world->mini.endian);
	//
	world->tmlx = tmlx;
}

int	**ft_init_texture(void)
{
	int	**ret;

	if (!(ret = (int **)malloc(sizeof(int *) * 8)))
	{
		return (0);
	}
	for (int i = 0; i < 8; i++)
	{
		if (!(ret[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W))))
		{
			//free(world->texture[i], i);
			//free(world->texture);
			return (0);
		}
		//world->texture[i] = ft_load_texture(world->tex_path[i], tmlx);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_H * TEX_W; j++)
		{
			ret[i][j] = 0;
		}
	}
	return (ret);
}

static void	ft_set_player_cardinal(t_player *p)
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

void	ft_set_minimap(t_world *world)
{
	int	w;
	int	h;
	int	size;

	(void)world;
	w = 0;
	while (w < mapWidth)
	{
		h = 0;
		size = 0;
		while (h < mapHeight)
		{
			if (map[w][h])
				world->minimap_buf[w][h] == 0x9966FF;
			else
				world->minimap_buf[w][h] == 0x996633;
			h++;
			size++;
		}
		w++;
	}
}

int	ft_init(t_mlx *tmlx, t_world *world)
{
	ft_init_mlx(tmlx, world);
	ft_init_buf(&world->buf);
	world->texture = ft_init_texture();
	tmp_load_texture(world);
	ft_init_player(&world->player);
	ft_set_minimap(world);
	//parse
	world->floor.rgb = 0x336600;
	world->ceiling.rgb = 0x0099FF;
	// world->map = map;
	//
	world->re = 0;
	return (1);
}
