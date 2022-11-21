/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:10:23 by sielee            #+#    #+#             */
/*   Updated: 2022/11/22 04:11:36 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	ft_background(t_world *world)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < world->screen_h / 2)
	{
		x = 0;
		while (x < world->screen_w)
		{
			world->screen_buf[y][x] = world->rgb.ceiling;
			world->screen_buf[world->screen_h - y - 1][x] = world->rgb.floor;
			x++;
		}
		y++;
	}
}

void	ft_init_rc(t_world *world, t_raycast *rc, size_t x)
{
	t_player	*p;

	p = &world->player;
	rc->cam_y = 2 * x / (double)world->screen_w - 1;
	rc->ray.x = p->dir.x + p->plane.x * rc->cam_y;
	rc->ray.y = p->dir.y + p->plane.y * rc->cam_y;
	rc->block.x = (int)p->pos.x;
	rc->block.y = (int)p->pos.y;
	rc->delta.x = fabs(1 / rc->ray.x);
	rc->delta.y = fabs(1 / rc->ray.y);
}

void	ft_step_dir(t_player *p,t_raycast *rc)
{
	if (rc->ray.x < 0)
	{
		rc->step.x = -1;
		rc->side.x = (p->pos.x - rc->block.x) * rc->delta.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side.x = (rc->block.x + 1.0 - p->pos.x) * rc->delta.x;
	}
	if (rc->ray.y < 0)
	{
		rc->step.y = -1;
		rc->side.y = (p->pos.y - rc->block.y) * rc->delta.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side.y = (rc->block.y + 1.0 - p->pos.y) * rc->delta.y;
	}
}

void	ft_check_hit(t_world *world, t_player *p, t_raycast *rc)
{
	while (1)
	{
		if (rc->side.x < rc->side.y)
		{
			rc->side.x += rc->delta.x;
			rc->block.x += rc->step.x;
			rc->is_side = 0;
		}
		else
		{
			rc->side.y += rc->delta.y;
			rc->block.y += rc->step.y;
			rc->is_side = 1;
		}
		if (world->map[rc->block.y][rc->block.x] == '1')
		{
			break ;
		}
	}
	if (rc->is_side == 0)
		rc->d = (rc->block.x - p->pos.x + (1 - rc->step.x) / 2.0) / rc->ray.x;
	else
		rc->d = (rc->block.y - p->pos.y + (1 - rc->step.y) / 2.0) / rc->ray.y;
}
