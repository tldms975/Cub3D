/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:01:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/16 01:19:46 by sielee           ###   ########seoul.kr  */
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

void	tmp_load_image(t_mlx *tmlx, int *texture, char *path, t_image *timg)
{
	int	y;
	int	x;

	y = 0;
	timg->img = mlx_xpm_file_to_image(tmlx->mlx, path, &timg->w, &timg->h);
	timg->data = (int *)mlx_get_data_addr(timg->img, &timg->bpp, &timg->line_len, &timg->endian);
	while (y < timg->h)
	{
		x = 0;
		while (x < timg->w)
		{
			texture[timg->w * y + x] = timg->data[timg->w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(tmlx->mlx, timg->img);
}

void	tmp_load_texture(t_world *world)
{
	t_image	timg;

	tmp_load_image(world->tmlx, world->texture[0], "textures/eagle.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[1], "textures/redbrick.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[2], "textures/purplestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[3], "textures/greystone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[4], "textures/bluestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[5], "textures/mossy.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[6], "textures/wood.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[7], "textures/colorstone.xpm", &timg);
}

int	**ft_init_texture(void)
{
	int	**ret;

	if (!(ret = (int **)malloc(sizeof(int *) * 8)))
	{
		return (0);
	}
	for (int i = 0; i < 8; i++)
	{
		if (!(ret[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W))))
		{
			//free(world->texture[i], i);
			//free(world->texture);
			return (0);
		}
		//world->texture[i] = ft_load_texture(world->tex_path[i], tmlx);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_H * TEX_W; j++)
		{
			ret[i][j] = 0;
		}
	}
	return (ret);
}
