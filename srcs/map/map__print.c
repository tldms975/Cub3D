/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 15:59:39 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include <stdio.h>

void	print_redzone(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height + 2)
	{
		j = 0;
		while (j + 1 < info->map.width + 2)
		{
			printf("%d", info->map.redzone[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("print_redzone\n");
}

void	print_raw(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j + 1 < info->map.raw[i]->length)
		{
			printf("%c", info->map.raw[i]->str[j]);
			j++;
		}
		printf(" : %zu\n", info->map.raw[i]->length);
		i++;
	}
	printf("print_raw\n");
}

void	print_visited(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.width)
		{
			printf("%d", info->map.visited[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("print_visited\n");
}
