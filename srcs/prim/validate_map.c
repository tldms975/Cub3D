/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/05 16:51:02 by hdoo             ###   ########.fr       */
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

bool	is_surrounded(t_info *info)
{
	bool	result;

	result = false;
	init_vertex(info);

		

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
