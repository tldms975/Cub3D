/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/10 15:41:37 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "info.h"
#include <stdio.h>

void	print_map(t_info *info, size_t x, size_t y);

char	find_valid_char(char target)
{
	const char	valid_char[VALID_C_NUM] = {' ', '0', '1', 'D', 'N', 'S', 'W', 'E'};
	int			i;

	i = 0;
	while (valid_char[i] != target)
	{
		i++;
	}
	if (i < VALID_C_NUM)
	{
		return (valid_char[i]);
	}
	return (0);
}

bool	add_start_point(t_info *info, char target)
{
	if (target != 0 && target > 'D')
	{
		if (info->core.world.player->cardinal != 0)
		{
			info->core.world.player->cardinal = target;
		}
		else
		{
			ft_putstr_fd("Error: Multiple start point founded\n", 2);
			return (false);
		}
	}
	return (true);
}

bool	find_start_point(t_info *info)
{
	size_t		i;
	size_t		j;
	int			target;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.width)
		{
			target = find_valid_char(info->map.raw[i]->str[j]);
			return (add_start_point(info, target));
		}
		i++;
	}
	ft_putstr_fd("Error: No start point\n", 2);
	return (false);
}


bool	precheck_map(t_info *info)
{
	if (find_start_point(info) == true
			&& 



	return (true);
}

t_result	validate_map(t_info *info)
{
	t_result	retval;

	retval = FAILURE;

	if (precheck_map(info) == true)
	{
	}
	return (retval);
}
