/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/10/26 16:48:14 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "t_mlx.h"
#include "t_motion.h"
#include "t_world.h"
# include <stdlib.h>


typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_camera
{
	t_vec				pos;
	t_vec				dir;
	t_vec				plane;
}				t_camera;



void	ft_event_close(t_mlx *obj)
{
	mlx_destroy_window(obj->mlx, obj->win);
	exit(0);
}

int	ft_event_red_cross(int keycode)
{
	(void) keycode;
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_event_move(int keycode, t_cub3d *obj)
{
	if (keycode == KEY_A)
		obj->origin.x -= 10;
	else if (keycode == KEY_W)
		obj->origin.y += 10;
	else if (keycode == KEY_D)
		obj->origin.x += 10;
	else if (keycode == KEY_S)
		obj->origin.y -= 10;
}

int	ft_key_press(t_keycode keycode, t_world *obj)
{
	if (keycode == KEY_ESC)
		ft_event_close(obj);
	else if (keycode == KEY_A || keycode == KEY_W \
	|| keycode == KEY_D || keycode == KEY_S)
		ft_event_move(keycode, obj);
	else if(keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		ft_event_look();
	return (EXIT_SUCCESS);
}

void	ft_init_mlx(t_mlx *tmlx)
{
	const int	w = 1920;
	const int	h = 1080;

	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, w, h, "cub3d");
	tmlx->timg.img = mlx_new_image(tmlx->mlx, w, h);
	tmlx->timg.addr = mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bits_per_pixel, &tmlx->timg.line_length, &tmlx->timg.endian);
}

void	ft_draw_world(t_world *cub)
{
	
}

void	ft_on_screen(t_mlx *tmlx, t_world	*world)
{
	ft_draw_world(world);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg.img, 0, 0);
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &ft_event_red_cross, 0);
	mlx_loop(tmlx, world);
}
