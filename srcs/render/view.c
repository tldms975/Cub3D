/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:16:55 by sielee            #+#    #+#             */
/*   Updated: 2022/11/24 18:12:30 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"
#include <math.h>
#include <stdio.h>

void	ft_move_sight(int keycode, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	theta;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	if (keycode == KEY_ARROW_R)
	{
		theta = p->rot_speed;
	}
	else if (keycode == KEY_ARROW_L)
	{
		theta = -p->rot_speed;
	}
	else
	{
		return ;
	}
	p->dir.x = p->dir.x * cos(theta) - p->dir.y * sin(theta);
	p->dir.y = old_dir_x * sin(theta) + p->dir.y * cos(theta);
	p->plane.x = p->plane.x * cos(theta) - p->plane.y * sin(theta);
	p->plane.y = old_plane_x * sin(theta) + p->plane.y * cos(theta);
}

void	ft_move_sight_mouse(int x, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	double	theta;
	t_player *p;

	p = &info->core.world.player;
	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;

	x -= info->core.world.screen_w / 2;
	theta = (((double)x / info->core.world.screen_w) * (M_PI / 180) * 66);
	p->dir.x = p->dir.x * cos(theta) - p->dir.y * sin(theta);
	p->dir.y = old_dir_x * sin(theta) + p->dir.y * cos(theta);
	p->plane.x = p->plane.x * cos(theta) - p->plane.y * sin(theta);
	p->plane.y = old_plane_x * sin(theta) + p->plane.y * cos(theta);
}
