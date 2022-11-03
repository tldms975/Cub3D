/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/03 23:21:24 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_coor	*find_start_point(t_info *info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (is_start_point(info, x, y))
			{
				add_start_point(info, x, y);
			}
			x++;
		}
		y++;
	}
	return ()
}

void	validate_map(t_info *info)
{
}


