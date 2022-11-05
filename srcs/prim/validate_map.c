/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/05 10:46:55 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	add_start_point(t_info *info, size_t x, size_t y)
{
	t_start_point	*st;

	st = &info->map.start_point;
	ft_realloc(st->coor, st->count * sizeof(t_start_point), st->capacity, &st->capacity);
	st->coor[st->count].c = info->map.raw[y]->str[x];
	st->coor[st->count].x = x;
	st->coor[st->count].y = y;
	st->count++;
}

bool	is_start_point(t_info *info, size_t x, size_t y)
{
	bool	retval;

	retval = false;
	if (info->map.raw[y]->str[x] == 'N'
			|| info->map.raw[y]->str[x] == 'S'
			|| info->map.raw[y]->str[x] == 'E'
			|| info->map.raw[y]->str[x] == 'W')
	{
		retval = true;
	}
	return (retval);
}

size_t	validate_char(t_info *info, size_t x, size_t y)
{
	char	target;
	char	valid_char[NUM_OF_VALID_CHAR] = {' ', '0', '1', 'N', 'S', 'E', 'W'};
	size_t		i;

	target = info->map.raw[y]->str[x];
	i = 0;
	while (i < NUM_OF_VALID_CHAR && target != valid_char[i])
	{
		i++;
	}
	return (i);
}

t_result	find_start_point(t_info *info)
{
	size_t		x;
	size_t		y;
	t_result	result;

	y = 0;
	result = true;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{


			if (validate_char(info, x, y) != NUM_OF_VALID_CHAR
					&& is_start_point(info, x, y))
			{

				{
					add_start_point(info, x, y);
				}
			}
			x++;
		}
		y++;
	}
	return (result);
}

t_result	validate_map(t_info *info)
{
	t_result	retval;

	retval = FAILURE;
	if (find_start_point(info) == SUCCESS
			&& is_surrounded(info) == true)
	{


	}
	return (retval);
}
