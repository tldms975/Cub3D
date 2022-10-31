/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/11/01 01:08:34 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "info.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		ft_memset(&info, 0, sizeof(t_info));
		if (parse_dot_cub(&info, argv) == SUCCESS)
		{
			printf("failed: parse_dot_cub\n");
		}
	}
	else
	{
		printf("Wrong number of arguments: expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
