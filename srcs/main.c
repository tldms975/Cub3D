/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/10/22 02:44:35 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "unistd.h"
// #include "cub3d.h"

typedef struct s_info
{
	int **map;
}	t_info;

int parse_info(t_info *info, int argc, char* argv[])
{
	(void)info;
	(void)argc;
	(void)argv;
	return (1);
}

int	main(int argc, char* argv[])
{
	t_info info;

	parse_info(&info, argc, argv);
	return (0);
}
