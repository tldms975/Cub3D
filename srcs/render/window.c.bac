/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/10/27 18:37:08 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "t_mlx.h"
#include "t_motion.h"
#include "t_world.h"
#include "t_engine.h"
# include <stdlib.h>

#define WIN_WIDTH 1200
#define WIN_HEIGHT 900

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

void	ft_move_player(int keycode, t_player *player)
{
	if (keycode == KEY_A)
		player->pos.x -= 10;
	else if (keycode == KEY_W)
		player->pos.y += 10;
	else if (keycode == KEY_D)
		player->pos.x += 10;
	else if (keycode == KEY_S)
		player->pos.y -= 10;
}

void	ft_move_sight(int keycode, t_player *player)
{
	if (keycode == KEY_ARROW_L)
		player->sight -= 10;//
	else if (keycode == KEY_ARROW_R)
		player->sight += 10;//
}

int	ft_key_press(t_keycode keycode, t_world *obj)
{
	if (keycode == KEY_ESC)
		ft_event_close(obj);
	else if (keycode == KEY_A || keycode == KEY_W \
	|| keycode == KEY_D || keycode == KEY_S)
		ft_move_player(keycode, obj);
	else if(keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		ft_move_sight();
	return (EXIT_SUCCESS);
}

void	ft_init_mlx(t_mlx *tmlx)
{
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");

	tmlx->timg.img = mlx_new_image(tmlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	tmlx->timg.addr = mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bits_per_pixel, &tmlx->timg.line_length, &tmlx->timg.endian);
}

void	ft_draw_world(t_world *world, t_mlx	*tmlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			world->buffer_window.data[y * WIN_WIDTH + x] = world->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg.img, 0, 0);
}

void	ft_on_window(t_render *render)
{
}

void	ft_render(t_mlx *tmlx, t_world	*world)
{
	ft_draw_world(world);
	
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &ft_event_red_cross, 0);
	mlx_loop(tmlx, world);
}

