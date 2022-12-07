/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/12/07 15:36:50 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "info.h"
#include "libft.h"
#include <stdio.h>

static void	free_info(t_info *info)
{
	size_t	i;

	i = 0;
	if (info->map.raw != NULL)
	{
		while (i < info->map.height)
		{
			str_free(info->map.raw[i]);
			i++;
		}
		free_safe(info->map.raw);
	}
	free_config(info);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		ft_bzero(&info, sizeof(info));
		if (parse_dot_cub(&info, argv[1]) == FAILURE)
		{
			printf("Error: Parse_dot_cub\n");
		}
		else
		{
			printf("SUCCESS: Parse_dot_cub\n");
			ft_run_cub3d(&info);
		}
		free_info(&info);
	}
	else
	{
		printf("Error: Wrong number of arguments: ");
		printf("expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
