/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:11:37 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 14:21:01 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types/t_keycode.h"

size_t	find_key(const int keycode)
{
	const int	key_table[] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_ARROW_L,
		KEY_ARROW_R, KEY_ESC, KEY_M, KEY_O, KEY_TAB};
	size_t		i;

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

int	ft_event_red_cross(int keycode)
{
	(void) keycode;
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
