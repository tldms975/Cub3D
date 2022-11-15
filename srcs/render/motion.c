/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:16 by sielee            #+#    #+#             */
/*   Updated: 2022/11/12 17:30:50 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
extern int map[mapWidth][mapHeight];

void	ft_move_left(t_player *p)
{
	if (!map[(int)(p->pos.x - p->dir.y * p->move_speed)][(int)(p->pos.y)])
		p->pos.x += -p->dir.y * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y + p->dir.x * p->move_speed)])
		p->pos.y += p->dir.x * p->move_speed;
}

void	ft_move_right(t_player *p)
{
	if (!map[(int)(p->pos.x + p->dir.y * p->move_speed)][(int)(p->pos.y)])
		p->pos.x += p->dir.y * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y - p->dir.x * p->move_speed)])
		p->pos.y += -p->dir.x * p->move_speed;
}

void	ft_move_backward(t_player *p)
{
	if (!map[(int)(p->pos.x - p->dir.x * p->move_speed)][(int)(p->pos.y)])
		p->pos.x -= p->dir.x * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y - p->dir.y * p->move_speed)])
		p->pos.y -= p->dir.y * p->move_speed;
}

void	ft_move_foreward(t_player *p)
{
	if (!map[(int)(p->pos.x + p->dir.x * p->move_speed)][(int)(p->pos.y)])
		p->pos.x += p->dir.x * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * p->move_speed)])
		p->pos.y += p->dir.y * p->move_speed;
}

void	ft_move_player(int keycode, t_player *p)
{
	if (keycode == KEY_W)
		ft_move_foreward(p);
	else if (keycode == KEY_S)
		ft_move_backward(p);
	else if (keycode == KEY_A)
		ft_move_left(p);
	else if (keycode == KEY_D)
		ft_move_right(p);
}

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