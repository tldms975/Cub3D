/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:14:53 by sielee            #+#    #+#             */
/*   Updated: 2022/12/04 18:18:11 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "cub3d.h"
#include <math.h>

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

int	ft_event_red_cross(int keycode)
{
	(void) keycode;
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

size_t	find_key(const int keycode)
{
	const int	key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_ARROW_L, KEY_ARROW_R, KEY_ESC, KEY_M, KEY_O, KEY_TAB};
	size_t	i;

	i = 0;
	while (i < sizeof(key_table) / sizeof(key_table[0]))
	{
		if (key_table[i] == keycode)
		{
			break ;
		}
		i++;
	}
	return (i);
}

t_keycode	which_is_functinal(t_keycode key1, t_keycode key2, int keycode)
{
	if ((keycode & 1 << find_key(key1)) && (keycode & 1 << find_key(key2)) == 0)
	{
		return (key1);
	}
	if ((keycode & 1 << find_key(key2)) && (keycode & 1 << find_key(key1)) == 0)
	{
		return (key2);
	}
	return (KEY_NONE);
}

void	ft_door(t_world *world)
{
	t_ivec		front;
	t_player	*p;
	p = &world->player;
	front.x = world->player.pos.x;
	front.y = world->player.pos.y;
	if (fabs(p->dir.x) < fabs(p->dir.y)) // N S
	{
		if (p->dir.y < 0)
			front.y -= 1;
		else
			front.y += 1;
	}
	else // W E
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
	printf("=======================\n");
	printf("pos(%f, %f)\n", p->pos.x, p->pos.y);
	printf("dir(%f, %f)\n", p->dir.x, p->dir.y);
	printf("pla(%f, %f)\n", p->plane.x, p->plane.y);
	printf("front(%d, %d) = %c\n", front.x, front.y, world->map[front.y][front.x]);
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

void	action_internal(const t_keycode key, t_world *world)
{
	const t_keycode	key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_ESC, KEY_M, KEY_O, KEY_TAB};
	const t_key_action	func_table[] =
	{
		ft_move_foreward, ft_move_left,
		ft_move_backward, ft_move_right,
		ft_event_close, ft_toggle_mouse,
		ft_door, ft_toggle_minimap
	};
	size_t	i;

	if (key == KEY_NONE)
	{
		return ;
	}
	i = 0;
	while (i < sizeof(key_table) / sizeof(key_table[0]))
	{
		if (key_table[i] == key)
		{
			func_table[i](world);
			break ;
		}
		i++;
	}
}

void	reset_mouse_pos(t_info *info)
{
	static int	count = 0;

	count++;
	if (count == 10)
	{
		info->mousecode = info->core.world.screen_w / 2;
		count = 0;
	}
}

void	action_by_each_keys(t_info *info)
{
	if (info->keycode & 1 << find_key(KEY_ESC))
	{
		action_internal(KEY_ESC, &info->core.world);
	}
	ft_move_sight(which_is_functinal(KEY_ARROW_R, KEY_ARROW_L, info->keycode),
			&info->core.world.player);
	action_internal(which_is_functinal(KEY_W, KEY_S, info->keycode), &info->core.world);
	action_internal(which_is_functinal(KEY_A, KEY_D, info->keycode), &info->core.world);
	if (info->keycode & 1 << find_key(KEY_M))
	{
		action_internal(KEY_M, &info->core.world);
	}
	if (info->keycode & 1 << find_key(KEY_TAB))
	{
		action_internal(KEY_TAB, &info->core.world);
	}
}

t_result	action(t_info *info)
{
	t_result	result;

	result = FAILURE;
	if (info->keycode != 0)
	{
		action_by_each_keys(info);
		result = SUCCESS;
	}
	if (info->core.world.mouse_on == true)
	{
		ft_move_sight_mouse(info->mousecode, info);
		mlx_mouse_move(info->core.mlx.win, info->core.world.screen_w / 2, 0);
		reset_mouse_pos(info);
		result = SUCCESS;
	}
	return (result);
}

int	ft_mouse_move(int x, int y, t_info *info)
{
	info->mousecode = x;
	(void)y;
	return (0);
}

int	ft_key_press(t_keycode keycode, t_info *info)
{
	info->keycode |= (1 << find_key(keycode));
	if (keycode == KEY_M)
	{
		ft_toggle_mouse(&info->core.world);
	}
	else if (keycode == KEY_O)
	{
		ft_door(&info->core.world);
	}
	else if(keycode == KEY_TAB)
	{
		ft_toggle_minimap(&info->core.world);
	}
	return (EXIT_SUCCESS);
}

int	ft_key_release(t_keycode keycode, t_info *info)
{
	info->keycode &= ~(1 << find_key(keycode));
	return (EXIT_SUCCESS);
}
