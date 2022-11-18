/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:13 by sielee            #+#    #+#             */
/*   Updated: 2022/11/18 18:37:00 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

int	ft_next_frame(void *w)
{
	t_world	*world;

	world = (t_world *)w;
	ft_set_world(world);
	ft_world_on_screen(world, world->tmlx);
	ft_minimap_on_screen(world, world->tmlx);
	return (EXIT_SUCCESS);
}

// int	ft_mouse_motion()
// {
// 	mlx_mouse_get_pos(p->)
// }

void	ft_render(t_world *world)
{
	t_mlx	*tmlx;

	tmlx = world->tmlx;
	ft_next_frame(world);
	mlx_loop_hook(tmlx->mlx, &ft_next_frame, (void *)world);
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &ft_event_red_cross, 0);
	// mlx_hook(tmlx->win, , 0, &ft_mouse_motion, 0);
	mlx_loop(tmlx->mlx);
}

void ft_run_cub3d(t_info *info)
{
	t_mlx	tmlx;
	t_world	world;

	if (ft_init_render(&tmlx, &world, info))
		ft_render(&world);
}
