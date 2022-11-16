/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veiw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:16:55 by sielee            #+#    #+#             */
/*   Updated: 2022/11/16 14:59:18 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

extern int map[MAP_W][MAP_H];

void	ft_move_sight(int keycode, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	if (keycode == KEY_ARROW_R)
	{
		p->dir.x = p->dir.x * cos(-p->rot_speed) - p->dir.y * sin(-p->rot_speed);
		p->dir.y = old_dir_x * sin(-p->rot_speed) + p->dir.y * cos(-p->rot_speed);
		p->plane.x = p->plane.x * cos(-p->rot_speed) - p->plane.y * sin(-p->rot_speed);
		p->plane.y = old_plane_x * sin(-p->rot_speed) + p->plane.y * cos(-p->rot_speed);
	}
	else if (keycode == KEY_ARROW_L)
	{
		p->dir.x = p->dir.x * cos(p->rot_speed) - p->dir.y * sin(p->rot_speed);
		p->dir.y = old_dir_x * sin(p->rot_speed) + p->dir.y * cos(p->rot_speed);
		p->plane.x = p->plane.x * cos(p->rot_speed) - p->plane.y * sin(p->rot_speed);
		p->plane.y = old_plane_x * sin(p->rot_speed) + p->plane.y * cos(p->rot_speed);
	}
}
