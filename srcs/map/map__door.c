/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:13:31 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/06 17:33:18 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "maps.h"
#include <stdio.h>

bool	map__door__check_sidewall(t_info *info, size_t x, size_t y)
{
	const bool	precheck[4] = {
		x > 1, x + 1 < info->map.raw[y]->length,
		y > 1 && x < info->map.raw[y - 1]->length,
		y + 1 < info->map.height && x < info->map.raw[y + 1]->length
	};

	if ((precheck[0] == true && info->map.raw[y]->str[x - 1] == '1'
			&& precheck[1] == true && info->map.raw[y]->str[x + 1] == '1')
		|| (precheck[2] == true && info->map.raw[y - 1]->str[x] == '1'
			&& precheck[3] == true && info->map.raw[y + 1]->str[x] == '1'))
	{
		return (true);
	}
	else
	{
		ft_putstr_fd("Error: Invalid door is found\n", 2);
		return (false);
	}
}

t_result	map__door__find(t_info *info)
{
	size_t	x;
	size_t	y;
	size_t	door_count;

	y = 0;
	door_count = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (info->map.raw[y]->str[x] == 'D')
			{
				if (map__door__check_sidewall(info, x, y) == true)
					door_count++;
				else
					return (FAILURE);
			}
			x++;
		}
		y++;
	}
	return (door_count > 0);
}

t_result	map__door__validate(t_info *info)
{
	t_result	result;

	result = map__door__find(info);
	printf("%zu", info->core.world.wall_tex_n);
	if (result == SUCCESS && info->core.world.wall_tex_n == 4)
	{
		ft_putstr_fd("Error: No door in config file\n", 2);
		result = FAILURE;
	}
	else if (result == FAILURE && info->core.world.wall_tex_n == 4)
	{
		result = SUCCESS;
	}
	return (result);
}
