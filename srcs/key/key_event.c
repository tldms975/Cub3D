/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:14:53 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 14:30:11 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "cub3d.h"
#include <math.h>
#include "key.h"

void	action_internal(const t_keycode key, t_world *world)
{
	size_t				i;
	const t_keycode		key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D,
		KEY_ESC, KEY_M, KEY_O, KEY_TAB};
	const t_key_action	func_table[] = {
		ft_move_foreward, ft_move_left,
		ft_move_backward, ft_move_right,
		ft_event_close, ft_toggle_mouse,
		ft_door, ft_toggle_minimap
	};

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

void	action_by_each_keys(t_info *info)
{
	if (info->keycode & 1 << find_key(KEY_ESC))
	{
		action_internal(KEY_ESC, &info->core.world);
	}
	if (info->keycode & 1 << find_key(KEY_M))
	{
		action_internal(KEY_M, &info->core.world);
	}
	if (info->keycode & 1 << find_key(KEY_TAB))
	{
		action_internal(KEY_TAB, &info->core.world);
	}
	ft_move_sight(which_is_functinal(KEY_ARROW_R, KEY_ARROW_L, info->keycode),
		&info->core.world.player);
	action_internal(which_is_functinal(KEY_W, KEY_S, info->keycode),
		&info->core.world);
	action_internal(which_is_functinal(KEY_A, KEY_D, info->keycode),
		&info->core.world);
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
