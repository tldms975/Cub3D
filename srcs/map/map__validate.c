/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:27:05 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_result	map__visit_zero(t_info *info)
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
	print_visited(info);
	print_raw(info);
	return (result);
}

static bool	map__precheck(t_info *info)
{
	map__visited_create(info);
	map__redzone_create(info);
	if (map__start_point__find(info) == true
		&& map__visit_zero(info) == SUCCESS)
	{
		return (true);
	}
	else
	{
		ft_putstr_fd("Error: Map precheck failed\n", 2);
		return (false);
	}
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
