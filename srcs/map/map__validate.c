/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 19:28:36 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include <stdio.h>

static t_result	map__dij__visit_zero(t_info *info)
{
	t_result	result;
	t_path		open;

	result = FAILURE;
	map__openpath_create(info, &open);
	while (open.count != 0)
	{
		result = map__dij__path__release(info, &open);
		if (result != SUCCESS)
		{
			break ;
		}
	}
	map__free_open_path(&open);
	print_visited(info);
	print_raw(info);
	return (result);
}

static bool	map__precheck(t_info *info)
{
	bool	result;

	map__visited_create(info);
	map__redzone_create(info);
	if (map__start_point__find(info) == true
		&& map__dij__visit_zero(info) == SUCCESS)
	{
		result = true;
	}
	else
	{
		ft_putstr_fd("Error: Map precheck failed\n", 2);
		result = false;
	}
	map__free_redzone(info);
	map__free_visited(info);
	return (result);
}

t_result	map__validate(t_info *info)
{
	t_result	retval;

	retval = FAILURE;
	if (map__precheck(info) == true)
	{
		retval = SUCCESS;
	}
	return (retval);
}
