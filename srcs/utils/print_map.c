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
	(void)x;
	for (size_t i = 0; i < info->map.height; i++)
	{
		if (i == y)
		{
			for (size_t j = 0; j < info->map.raw[y]->length; j++)
			{
				if (j == x)
				{
					printf("%s%c%s", RED, 'X', NOCOLOR);
				}
				else
					printf("%c", info->map.raw[y]->str[j]);
			}
		}
		else
			printf("%s", str_dispose(info->map.raw[i]));
	}
}
