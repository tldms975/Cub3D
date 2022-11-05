/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:00:26 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/05 16:00:49 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_start_point(t_info *info, size_t x, size_t y)
{
	t_start_point	*st;

	st = &info->map.start_point;
	ft_realloc(st->coor, (st->count + 1) * sizeof(t_start_point), st->capacity, &st->capacity);
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
	size_t	i;

	target = info->map.raw[y]->str[x];
	i = 0;
	while (i < NUM_OF_VALID_CHAR && target != valid_char[i])
	{
		i++; }
	return (i);
}

t_result	parse_curr_char(t_info *info, size_t x, size_t y)
{
	t_result	result;
	size_t		index;

	result = SUCCESS;
	index = validate_char(info, x, y);
	if (index < NUM_OF_VALID_CHAR)
	{
		if (index > 2)
		{
			add_start_point(info, x, y);
		}
	}
	else
	{
		result = FAILURE;
	}
	return (result);
}

t_result	gether_start_point(t_info *info)
{
	size_t		x;
	size_t		y;
	t_result	result;

	y = 0;
	result = SUCCESS;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (parse_curr_char(info, x, y) == FAILURE)
			{
				result = FAILURE;
				break ;
			}
			x++;
		}
		y++;
	}
	return (result);
}
