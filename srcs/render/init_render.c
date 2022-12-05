/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:34 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 15:49:25 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"
#include "types/t_keycode.h"
#include <math.h>

static void	ft_init_mlx(t_info *info)
{
	t_mlx	*tmlx;
	t_world	*world;

	tmlx = &info->core.mlx;
	world = &info->core.world;
	tmlx->mlx = mlx_init();
	tmlx->win
		= mlx_new_window(tmlx->mlx, world->screen_w, world->screen_h, "cub3d");
	tmlx->timg_main.img
		= mlx_new_image(tmlx->mlx, world->screen_w, world->screen_h);
	tmlx->timg_main.data = (int *)mlx_get_data_addr(tmlx->timg_main.img, \
	&tmlx->timg_main.bpp, &tmlx->timg_main.line_len, &tmlx->timg_main.endian);
	tmlx->timg_mini.img
		= mlx_new_image(tmlx->mlx, world->minimap_w, world->minimap_h);
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
	p->dir.x = 0.0;
	p->dir.y = -1.0;
	p->plane.x = 0.5;
	p->plane.y = 0.0; // TODO - explain plain
	p->move_speed = 0.04;
	p->rot_speed = 0.05;
	ft_set_player_cardinal(p);
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
