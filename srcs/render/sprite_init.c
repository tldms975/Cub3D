/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:14:41 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 21:15:55 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	ft_init_sprite(t_sprite *s, t_player *p)
{
	s->pos.x = s->coor.x - p->pos.x;
	s->pos.y = s->coor.y - p->pos.y;
	s->idet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	s->tr.x = s->idet * (p->dir.y * s->pos.x - p->dir.x * s->pos.y);
	s->tr.y = s->idet * (-p->plane.y * s->pos.x + p->plane.x * s->pos.y);
	s->screen_x = (int)((WIN_W / 2.0) * (1.0 + s->tr.x / s->tr.y));
	s->u_div = 1;
	s->v_div = 1;
	s->v_move = 0;
	s->v_move_screen = (int)(s->v_move / s->tr.y);
	s->h = (int)fabs((WIN_H / s->tr.y) / s->v_div);
	s->dr_y.start = -s->h / 2.0 + WIN_H / 2.0 + s->v_move_screen;
	s->dr_y.end = s->h / 2.0 + WIN_H / 2.0 + s->v_move_screen;
	if (s->dr_y.start < 0)
		s->dr_y.start = 0;
	if (s->dr_y.end >= WIN_H)
		s->dr_y.end = WIN_H;
	s->w = (int)fabs((WIN_H / s->tr.y) / s->u_div);
	s->dr_x.start = -s->w / 2 + s->screen_x;
	s->dr_x.end = s->w / 2 + s->screen_x;
	if (s->dr_x.start < 0)
		s->dr_x.start = 0;
	if (s->dr_x.end >= WIN_W)
		s->dr_x.end = WIN_W;
}

int	init_order(int **ret, int n)
{
	*ret = malloc_safe(sizeof(int) * n);
	if (n == 1)
	{
		(*ret)[0] = 0;
		return (1);
	}
	return (0);
}

void	init_spr_arr(t_sprite *s, t_spr_arr **arr, int n)
{
	int	i;

	i = 0;
	*arr = malloc_safe(sizeof(t_spr_arr) * n);
	while (i < n)
	{
		(*arr)[i].id = i;
		(*arr)[i].d = pow(s[i].pos.x, 2) + pow(s[i].pos.y, 2);
		i++;
	}
}
