/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/22 06:16:01 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"
#include "types/t_keycode.h"
#include <math.h>
#include <stdio.h>

static void	ft_create_minimap_buf(t_info *info)
{
	size_t	i;

	info->core.world.minimap_w = info->map.width * 3;
	info->core.world.minimap_h = info->map.height * 6;
	info->core.world.minimap_buf = malloc(sizeof(int *) * (info->core.world.minimap_h));
	i = 0;
	while (i < info->core.world.minimap_h)
	{
		info->core.world.minimap_buf[i] = malloc(sizeof(int) * (info->core.world.minimap_w));
		ft_memset(info->core.world.minimap_buf[i], 0, sizeof(int) * (info->core.world.minimap_w));
		i++;
	}
}

static void	ft_init_mlx(t_info *info)
{
	t_mlx	*tmlx;
	t_world	*world;

	tmlx = &info->core.mlx;
	world = &info->core.world;
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, world->screen_w, world->screen_h, "cub3d");
	tmlx->timg_main.img = mlx_new_image(tmlx->mlx, world->screen_w, world->screen_h);
	tmlx->timg_main.data = (int *)mlx_get_data_addr(tmlx->timg_main.img, \
	&tmlx->timg_main.bpp, &tmlx->timg_main.line_len, &tmlx->timg_main.endian);
	tmlx->timg_mini.img = mlx_new_image(tmlx->mlx, world->minimap_w, world->minimap_h);
	tmlx->timg_mini.data = (int *)mlx_get_data_addr(tmlx->timg_mini.img, \
	&tmlx->timg_mini.bpp, &tmlx->timg_mini.line_len, &tmlx->timg_mini.endian);
	world->tmlx = tmlx;
}

static void	ft_set_player_cardinal(t_player *p)
{
	double	degree;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	degree = 0;
	if (p->cardinal == 'N')
		return ;
	else if (p->cardinal == 'W')
		degree = M_PI / 2;
	else if (p->cardinal == 'S')
		degree = M_PI;
	else if (p->cardinal == 'E')
		degree = M_PI * 3 / 2;
	p->dir.x = p->dir.x * cos(-degree) - p->dir.y * sin(-degree);
	p->dir.y = old_dir_x * sin(-degree) + p->dir.y * cos(-degree);
	p->plane.x = p->plane.x * cos(-degree) - p->plane.y * sin(-degree);
	p->plane.y = old_plane_x * sin(-degree) + p->plane.y * cos(-degree);
	return ;
}

static void	ft_init_player(t_player *p)
{
	p->pos.x += 0.5; // TODO - adjust player position
	p->pos.y += 0.5;
	p->dir.y = -1.0;
	p->dir.x = 0.0;
	p->plane.y = 0.0; // TODO - explain plain
	p->plane.x = 0.66;
	p->move_speed = 0.05;
	p->rot_speed = 0.08;
	ft_set_player_cardinal(p);
}

// static char	**ft_get_map(t_map *m)
// {
// 	char	**map;
// 	size_t	y;
// 	// size_t	x;
//
// 	map = malloc_safe(sizeof(char *) * m->height);
// 	y = 0;
// 	while (y < m->height)
// 	{
// 		// x = 0;
// 		// while (x < m->raw[y]->length)
// 		// {
// 			map[y] = malloc_safe(sizeof(char) * m->raw[y]->length);
// 			map[y] = m->raw[y]->str;
// 			//printf("%s\n", m->raw[y]->str);
// 			// x++;
// 		// }
// 		y++;
// 	}
// 	return (map);
// }

void ft_change_map_format(t_info *info)
{
	size_t	i;

	info->core.world.map = malloc_safe(sizeof(char *) * info->map.height);
	i = 0;
	while (i < info->map.height)
	{
		info->core.world.map[i] = malloc_safe(sizeof(char) * info->map.width);
		ft_memset(info->core.world.map[i], ' ', info->map.width);
		ft_memcpy(info->core.world.map[i], info->map.raw[i]->str, info->map.raw[i]->length);
		i++;
	}
}

void	set_screen_size(t_info *info)
{
	info->core.world.screen_w = 640;
	info->core.world.screen_h = 480;
}

void	ft_create_screen_buf(t_info *info)
{
	size_t	i;

	info->core.world.screen_buf = malloc_safe(sizeof(int *) * info->core.world.screen_h);
	i = 0;
	while (i < info->core.world.screen_h)
	{
		info->core.world.screen_buf[i] = malloc_safe(sizeof(int) * info->core.world.screen_w);
		ft_memset(info->core.world.screen_buf[i], 0, sizeof(int) * info->core.world.screen_w);
		i++;
	}
}

int	ft_init_render(t_info *info)
{
	set_screen_size(info);
	ft_change_map_format(info);
	ft_create_screen_buf(info);
	ft_create_minimap_buf(info);
	ft_set_minimap(info);
	ft_init_mlx(info);
	ft_load_texture(info);
	ft_init_player(&info->core.world.player);
	return (1);
}
