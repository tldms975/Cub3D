/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/11/12 03:14:54 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "info.h"
#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		ft_bzero(&info, sizeof(info));
		if (parse_dot_cub(&info, argv[1]) == FAILURE)
		{
			printf("Error: parse_dot_cub\n");
		}
		else
		{
			printf("SUCCESS: parse_dot_cub\n");
		}
	}
	else
	{
		printf("Error: Wrong number of arguments: expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
