/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:01:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/18 15:49:25 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	*ft_load_image(char *path, t_mlx *tmlx)
{
	int		*res;

	tmlx->timg.img = mlx_xpm_file_to_image(tmlx->mlx, path, &tmlx->timg.w, \
	&tmlx->timg.h);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);

	res = (int *)malloc(sizeof(int) * (tmlx->timg.w * tmlx->timg.h));
	for (int y = 0; y < tmlx->timg.h; y++)
	{
		for (int x = 0; x < tmlx->timg.w; x++)
		{
			res[tmlx->timg.w * y + x] = tmlx->timg.data[tmlx->timg.w * y + x];
		}
	}
	mlx_destroy_image(tmlx->mlx, &tmlx->timg.img);
	return (res);
}

void	ft_load_texture(t_world *world)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		world->texture[i] = ft_load_image(world->tex_path[i], world->tmlx);
		i++;
	}
}

// void	ft_load_texture(t_world *world)
// {
// 	t_image	timg;

// 	ft_load_image(world->tmlx, world->texture[0], world->tex_path[0], &timg);
// 	ft_load_image(world->tmlx, world->texture[1], world->tex_path[1], &timg);
// 	ft_load_image(world->tmlx, world->texture[2], world->tex_path[2], &timg);
// 	ft_load_image(world->tmlx, world->texture[3], world->tex_path[3], &timg);
// }

// int	**ft_init_texture(void)
// {
// 	int	**ret;

// 	if (!(ret = (int **)malloc(sizeof(int *) * 8)))
// 	{
// 		return (0);
// 	}
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (!(ret[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W))))
// 		{
// 			//free(world->texture[i], i);
// 			//free(world->texture);
// 			return (0);
// 		}
// 		//world->texture[i] = ft_load_texture(world->tex_path[i], tmlx);
// 	}
// 	for (int i = 0; i < 8; i++)
// 	{
// 		for (int j = 0; j < TEX_H * TEX_W; j++)
// 		{
// 			ret[i][j] = 0;
// 		}
// 	}
// 	return (ret);
// }
