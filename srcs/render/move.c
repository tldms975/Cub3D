/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:16 by sielee            #+#    #+#             */
/*   Updated: 2022/11/15 21:24:31 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
extern int map[MAP_W][MAP_H];

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
