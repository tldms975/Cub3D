/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:16 by sielee            #+#    #+#             */
/*   Updated: 2022/11/18 19:29:28 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	ft_move_right(t_world *w, t_player *p)
{
	if (p->pos.y < w->map[(int)p->pos.x]->length &&
			!w->map[(int)(p->pos.x - p->dir.y * p->move_speed)]->str[(int)(p->pos.y)])
		p->pos.x += -p->dir.y * p->move_speed;
	if (p->pos.y < w->map[(int)p->pos.x]->length &&
			!w->map[(int)(p->pos.x)]->str[(int)(p->pos.y + p->dir.x * p->move_speed)])
		p->pos.y += p->dir.x * p->move_speed;
}

void	ft_move_left(t_world *w, t_player *p)
{
	if (p->pos.y < w->map[(int)(p->pos.x + p->dir.y * p->move_speed)]->length &&
			!w->map[(int)(p->pos.x + p->dir.y * p->move_speed)]->str[(int)(p->pos.y)])
		p->pos.x += p->dir.y * p->move_speed;
	if (p->pos.y < w->map[(int)(p->pos.x)]->length &&
			!w->map[(int)(p->pos.x)]->str[(int)(p->pos.y - p->dir.x * p->move_speed)])
		p->pos.y += -p->dir.x * p->move_speed;
}

void	ft_move_backward(t_world *w, t_player *p)
{
	if (p->pos.y < w->map[(int)(p->pos.x - p->dir.x * p->move_speed)]->length &&
			!w->map[(int)(p->pos.x - p->dir.x * p->move_speed)]->str[(int)(p->pos.y)])
		p->pos.x -= p->dir.x * p->move_speed;
	if (p->pos.y < w->map[(int)(p->pos.x)]->length &&
			!w->map[(int)(p->pos.x)]->str[(int)(p->pos.y - p->dir.y * p->move_speed)])
		p->pos.y -= p->dir.y * p->move_speed;
}

void	ft_move_foreward(t_world *w, t_player *p)
{
	if (p->pos.y < w->map[(int)(p->pos.x + p->dir.x * p->move_speed)]->length &&
			!w->map[(int)(p->pos.x + p->dir.x * p->move_speed)]->str[(int)(p->pos.y)])
		p->pos.x += p->dir.x * p->move_speed;
	if (p->pos.y < w->map[(int)(p->pos.x)]->length &&
			!w->map[(int)(p->pos.x)]->str[(int)(p->pos.y + p->dir.y * p->move_speed)])
		p->pos.y += p->dir.y * p->move_speed;
}

void	ft_move_player(int keycode, t_world *w, t_player *p)
{
	if (keycode == KEY_W)
		ft_move_foreward(w, p);
	else if (keycode == KEY_S)
		ft_move_backward(w, p);
	else if (keycode == KEY_A)
		ft_move_left(w, p);
	else if (keycode == KEY_D)
		ft_move_right(w, p);
}
