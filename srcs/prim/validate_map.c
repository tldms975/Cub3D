/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/06 21:15:29 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "info.h"
#include <stdio.h>

void	print_map(t_info *info, size_t x, size_t y);


typedef struct s_valid_path
{
	t_coor	*path;
	
}	t_valid_path;

t_coor	init_vertex(t_info *info)
{
	size_t	i;
	size_t	j;
	t_coor	result;

	i = 0;
	ft_memset(&result, 0, sizeof(t_coor));
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.raw[i]->length)
		{
			if (info->map.raw[i]->str[j] == '1')
			{
				result.x = j;
				result.y = i;
				result.c = info->map.raw[i]->str[j];
				return (result);
			}
			j++;
		}
		i++;
	}
	return (result);
}

bool	is_same(t_coor first, t_coor next)
{
	return (first.x == next.x && first.y == next.y);
}

bool	find_wall_not_visited(t_info *info, t_coor curr)
{
	const bool	lower_x_precheck = curr.x > 1;
	const bool	upper_x_precheck = curr.x + 1 < info->map.raw[curr.y]->length;
	const bool	lower_y_precheck = (curr.y > 1 && curr.x < info->map.raw[curr.y - 1]->length);
	const bool	upper_y_precheck = (curr.y + 1 < info->map.height
			&& curr.x < info->map.raw[curr.y + 1]->length);

	return (false);
}

size_t	release_path(t_info *info, t_coor curr)
{



}

bool	is_surrounded(t_info *info)
{
	bool	result;
	t_coor	first_node;
	t_coor	curr_node;

	result = false;
	first_node = init_vertex(info);

	info->map.opened.path = malloc_safe(sizeof(t_coor) * 100);
	while (is_same(first_node, curr_node) != true)
	{
		release_path(info, curr_node);

	}

		

	return (result);
}

t_result	validate_map(t_info *info)
{
	t_result	retval;

	retval = FAILURE;

	if (is_surrounded(info) == true
			&& gether_start_point(info) == SUCCESS)
	{
	}
	return (retval);
}
