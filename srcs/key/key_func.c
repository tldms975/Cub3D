/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:09:26 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 14:30:07 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>

void	ft_door(t_world *world)
{
	t_ivec		front;
	t_player	*p;

	p = &world->player;
	front.x = world->player.pos.x;
	front.y = world->player.pos.y;
	if (fabs(p->dir.x) < fabs(p->dir.y))
	{
		if (p->dir.y < 0)
			front.y -= 1;
		else
			front.y += 1;
	}
	else
	{
		if (p->dir.x > 0)
			front.x += 1;
		else
			front.x -= 1;
	}
	if (world->map[front.y][front.x] == 'D')
		world->map[front.y][front.x] = 'd';
	else if (world->map[front.y][front.x] == 'd')
		world->map[front.y][front.x] = 'D';
}

void	ft_toggle_minimap(t_world *world)
{
	static int	count = 0;

	count++;
	if (world->minimap_on == false && count == 10)
	{
		world->minimap_on = true;
		count = 0;
	}
	else if (count == 10)
	{
		world->minimap_on = false;
		count = 0;
	}
}

void	ft_toggle_mouse(t_world *world)
{
	static int	count = 0;

	count++;
	if (world->mouse_on == false && count == 10)
	{
		world->mouse_on = true;
		mlx_mouse_hide();
		count = 0;
	}
	else if (count == 10)
	{
		world->mouse_on = false;
		mlx_mouse_show();
		count = 0;
	}
}

void	ft_event_close(t_world *world)
{
	mlx_destroy_window(world->tmlx->mlx, world->tmlx->win);
	exit(EXIT_SUCCESS);
}

int	ft_mouse_move(int x, int y, t_info *info)
{
	info->mousecode = x;
	(void)y;
	return (0);
}
