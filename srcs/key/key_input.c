/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:10:20 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 14:20:25 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types/t_keycode.h"
#include "mlx.h"
#include <math.h>
#include "key.h"

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
	else if (keycode == KEY_TAB)
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
