/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:14:53 by sielee            #+#    #+#             */
/*   Updated: 2022/11/21 22:34:01 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_event_close(t_mlx *tmlx)
{
	mlx_destroy_window(tmlx->mlx, tmlx->win);
	exit(0);
}

int	ft_event_red_cross(int keycode)
{
	(void) keycode;
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	ft_key_press(t_keycode keycode, t_world *world)
{
	if (keycode == KEY_ESC)
		ft_event_close(world->tmlx);
	else if (keycode == KEY_A || keycode == KEY_W \
	|| keycode == KEY_D || keycode == KEY_S)
		ft_move_player(keycode, world);
	else if(keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		ft_move_sight(keycode, &world->player);
	mlx_clear_window(world->tmlx->mlx, world->tmlx->win);
	ft_next_frame(world);
	return (EXIT_SUCCESS);
}
