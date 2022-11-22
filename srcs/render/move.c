/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:16 by sielee            #+#    #+#             */
/*   Updated: 2022/11/22 20:59:39 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include <stdio.h>

void	ft_move_right(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.y * p->move_speed)] != '1')
		p->pos.x += -p->dir.y * p->move_speed;
	if (world->map[(int)(p->pos.y + p->dir.x * p->move_speed)] \
	[(int)(p->pos.x)] != '1')
		p->pos.y += p->dir.x * p->move_speed;
}

void	ft_move_left(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (world->map[(int)p->pos.y] \
	[(int)(p->pos.x + p->dir.y * p->move_speed)] != '1')
		p->pos.x += p->dir.y * p->move_speed;
	if (world->map[(int)(p->pos.y - p->dir.x * p->move_speed)] \
	[(int)p->pos.x] != '1')
		p->pos.y += -p->dir.x * p->move_speed;
}

void	ft_move_backward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.x * p->move_speed)] != '1')
		p->pos.x -= p->dir.x * p->move_speed;
	if (world->map[(int)(p->pos.y - p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)] != '1')
		p->pos.y -= p->dir.y * p->move_speed;
}

void	ft_move_foreward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x + p->dir.x * p->move_speed)] != '1')
		p->pos.x += p->dir.x * p->move_speed;
	if (world->map[(int)(p->pos.y + p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)] != '1')
		p->pos.y += p->dir.y * p->move_speed;
}

void	ft_move_player(int keycode, t_world *world)
{
	if (keycode == KEY_W)
		ft_move_foreward(world);
	else if (keycode == KEY_S)
		ft_move_backward(world);
	else if (keycode == KEY_A)
		ft_move_left(world);
	else if (keycode == KEY_D)
		ft_move_right(world);
}
