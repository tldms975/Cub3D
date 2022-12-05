/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:58:34 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 04:48:52 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	print_map(t_info *info, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height)
	{
		if (i == y)
		{
			j = 0;
			while (j < info->map.raw[y]->length)
			{
				if (j == x)
					printf("%s%c%s", RED, 'X', NOCOLOR);
				else
					printf("%c", info->map.raw[y]->str[j]);
				j++;
			}
		}
		else
			printf("%s", str_dispose(info->map.raw[i]));
		i++;
	}
}
