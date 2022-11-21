/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:01:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/22 05:38:45 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "types/t_mlx.h"
#include <stdio.h>

int	*ft_load_image(char *path, t_mlx *tmlx, int i)
{
	int		*res;
	int		y;
	int		x;

	tmlx->timg_texture[i].img = mlx_xpm_file_to_image(tmlx->mlx, path, &tmlx->timg_texture[i].w, \
	&tmlx->timg_texture[i].h);
	tmlx->timg_texture[i].data = (int *)mlx_get_data_addr(tmlx->timg_texture[i].img, \
	&tmlx->timg_texture[i].bpp, &tmlx->timg_texture[i].line_len, &tmlx->timg_texture[i].endian);
	res = (int *)malloc(sizeof(int) * (tmlx->timg_texture[i].w * tmlx->timg_texture[i].h));
	y = 0;
	while (y < tmlx->timg_texture[i].h)
	{
		x = 0;
		while (x < tmlx->timg_texture[i].w)
		{
			res[tmlx->timg_texture[i].w * y + x] = tmlx->timg_texture[i].data[tmlx->timg_texture[i].w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(tmlx->mlx, tmlx->timg_texture[i].img);
	return (res);
}

void	ft_load_texture(t_info *info)
{
	int	i;
	t_world	*world;

	world = &info->core.world;
	i = 0;
	while (i < 4)
	{
		world->texture[i] = ft_load_image(world->tex_path[i], world->tmlx, i);
		i++;
	}
}
