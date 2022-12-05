/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:13:31 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 20:13:38 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "maps.h"

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
	return (false);
}

t_result	map__door__find(t_info *info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (info->map.raw[y]->str[x] == 'D'
					&& map__door__check_sidewall(info, x, y) == false)
			{
				ft_putstr_fd("Error: Invalid door is found\n", 2);
				return (FAILURE);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

t_result	map__door__validate(t_info *info)
{
	if (info->core.world.wall_tex_n > 4)
	{
		return (map__door__find(info));
	}
	else
	{
		ft_putstr_fd("Error: No door in config file\n", 2);
		return (FAILURE);
	}
}
