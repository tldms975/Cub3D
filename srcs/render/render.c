/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:13 by sielee            #+#    #+#             */
/*   Updated: 2022/12/03 18:58:35 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include <stdio.h>

int	ft_next_frame(void *i)
{
	t_info	*info;

	info = (t_info *)i;
	if (action(info) == SUCCESS)
	{
		ft_set_world(info);
		ft_world_on_screen(info, info->core.world.tmlx);
		if (info->core.world.minimap_on == true)
		{
			ft_minimap_on_screen(info, info->core.world.tmlx);
		}
	}
	return (EXIT_SUCCESS);
}

void	ft_render(t_info *info)
{
	t_mlx	*tmlx;

	tmlx = info->core.world.tmlx;
	ft_set_world(info);
	ft_world_on_screen(info, info->core.world.tmlx);
	mlx_loop_hook(tmlx->mlx, &ft_next_frame, info);
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, info);
	mlx_hook(tmlx->win, X_EVENT_KEY_RELEASE, 0, &ft_key_release, info);
	mlx_hook(tmlx->win, X_EVENT_ON_MOUSEMOVE, 0, &ft_mouse_move, info);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &ft_event_red_cross, 0);
	mlx_loop(tmlx->mlx);
}

void	ft_run_cub3d(t_info *info)
{
	if (ft_init_render(info))
	{
		ft_render(info);
	}
}
