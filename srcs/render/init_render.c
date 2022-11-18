/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/18 15:51:02 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

static void	ft_init_minimap_buf(int (*buf)[MINI_H][MINI_W])
{
	int	w;
	int	h;

	h = 0;
	while (h < MINI_H)
	{
		w = 0;
		while (w < MINI_W)
		{
			(*buf)[h][w] = 0;
			w++;
		}
		h++;
	}
}

static void	ft_init_mlx(t_mlx *tmlx, t_world *world)
{
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_W, WIN_H, "cub3d");
	tmlx->timg.img = mlx_new_image(tmlx->mlx, WIN_W, WIN_H);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);
	world->minimap.img = mlx_new_image(tmlx->mlx, MINI_W, MINI_H);
	world->minimap.data =  (int *)mlx_get_data_addr(world->minimap.img, \
	&world->minimap.bpp, &world->minimap.line_len, &world->minimap.endian);
	world->tmlx = tmlx;
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

static void	ft_init_player(t_player *p)
{
	// p->pos.x =22.5;//in parse
	// p->pos.y =22.5;//in parse
	p->dir.y = -0.9543;
	p->dir.x = 0.02;
	p->plane.y = 0.0;
	p->plane.x = 0.66;
	p->move_speed = 0.05;
	p->rot_speed = 0.08;
	ft_set_player_cardinal(p);
}

static char	**ft_get_map(t_map *m)
{
	char	**map;
	size_t	y;
	// size_t	x;

	map = malloc_safe(sizeof(char *) * m->height);
	y = 0;
	while (y < m->height)
	{
		// x = 0;
		// while (x < m->raw[y]->length)
		// {
			map[y] = malloc_safe(sizeof(char) * m->raw[y]->length);
			map[y] = m->raw[y]->str;
			//printf("%s\n", m->raw[y]->str);
			// x++;
		// }
		y++;
	}
	return (map);
}

int	ft_init_render(t_mlx *tmlx, t_world *world, t_info *info)
{
	ft_init_mlx(tmlx, world);
	ft_init_screen_buf(&world->screen_buf);
	world->map = ft_get_map(&info->map);
	ft_load_texture(world);
	ft_init_player(&world->player);
	ft_init_minimap_buf(&world->minimap_buf);
	ft_set_minimap(world);
	world->re = 0;
	return (1);
}
