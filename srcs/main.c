/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/12/06 20:39:37 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "info.h"
#include "libft.h"
#include <stdio.h>

static void	free_img(t_info *info)
{
	size_t	i;
	t_world	*world;

	world = &info->core.world;
	i = 0;
	while (i < info->core.world.wall_tex_n)
	{
		mlx_destroy_image(world->tmlx->mlx, &world->tmlx->timg_wall_tex[i].img);
		i++;
	}
	i = 0;
	if (!world->spr)
		return ;
	while (i < world->spr_tex_cnt)
	{
		mlx_destroy_image(world->tmlx->mlx, &world->tmlx->timg_spr_tex[i].img);
		i++;
	}
}

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
	free_img(info);
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
