/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:16 by sielee            #+#    #+#             */
/*   Updated: 2022/12/02 21:08:18 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include <stdio.h>

static	bool	is_space(char spot)
{
	if (spot == '1' || spot == 'D' || spot == 'T')
		return (0);
	return (1);
}

void	ft_move_right(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.y * p->move_speed)]))
		p->pos.x += -p->dir.y * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y + p->dir.x * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += p->dir.x * p->move_speed;
}

void	ft_move_left(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x + p->dir.y * p->move_speed)]))
		p->pos.x += p->dir.y * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y - p->dir.x * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += -p->dir.x * p->move_speed;
}

void	ft_move_backward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x - p->dir.x * p->move_speed)]))
		p->pos.x -= p->dir.x * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y - p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y -= p->dir.y * p->move_speed;
}

void	ft_move_foreward(t_world *world)
{
	t_player	*p;

	p = &world->player;
	if (is_space(world->map[(int)(p->pos.y)] \
	[(int)(p->pos.x + p->dir.x * p->move_speed)]))
		p->pos.x += p->dir.x * p->move_speed;
	if (is_space(world->map[(int)(p->pos.y + p->dir.y * p->move_speed)] \
	[(int)(p->pos.x)]))
		p->pos.y += p->dir.y * p->move_speed;
}
