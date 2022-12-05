/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:01:59 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 15:57:31 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "types/t_mlx.h"
#include <math.h>
#include <stdio.h>

int	ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	color = 0;
	dr->tex.y = (int)tex->pos & (world->tmlx->timg_wall_tex[tex->type].h - 1);
	tex->pos += tex->step;
	color = world->wall_tex[tex->type] \
			[(int)(world->tmlx->timg_wall_tex[tex->type].h
				* dr->tex.y + dr->tex.x)];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}

void	ft_wear_texture(t_world *world, t_raycast *rc, t_texture *tex, \
t_draw *dr)
{
	tex->wall_x -= floor(tex->wall_x);
	dr->tex.x
		= (int)(tex->wall_x * (double)world->tmlx->timg_wall_tex[tex->type].w);
	if ((rc->is_side == 0 && rc->ray.x > 0)
		|| (rc->is_side == 1 && rc->ray.y < 0))
	{
		dr->tex.x = world->tmlx->timg_wall_tex[tex->type].w - dr->tex.x - 1;
	}
	tex->step = 1.0 * world->tmlx->timg_wall_tex[tex->type].h / dr->line_h;
	tex->pos
		= (dr->start - world->screen_h / 2.0 + dr->line_h / 2.0) * tex->step;
}

int	*ft_load_image(char *path, t_mlx *tmlx, t_image *img)
{
	int	*res;
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(tmlx->mlx, path, &img->w, &img->h);
	img->data = (int *)mlx_get_data_addr(img->img, \
	&img->bpp, &img->line_len, &img->endian);
	res = (int *)malloc_safe(sizeof(int) * (img->w * img->h));
	y = -1;
	while (++y < img->h)
	{
		x = -1;
		while (++x < img->w)
		{
			res[img->w * y + x] = img->data[img->w * y + x];
		}
	}
	mlx_destroy_image(tmlx->mlx, img->img);
	return (res);
}

void	ft_load_texture(t_info *info)
{
	t_world	*world;
	size_t	i;

	world = &info->core.world;
	i = 0;
	while (i < info->core.world.wall_tex_n)
	{
		world->wall_tex[i] = ft_load_image(world->tex_path[i], \
		world->tmlx, &world->tmlx->timg_wall_tex[i]);
		i++;
	}
	i = 0;
	if (!world->spr)
		return ;
	while (i < world->spr_tex_cnt)
	{
		world->spr_tex[i] = ft_load_image(world->spr_tex_path[i], \
		world->tmlx, &world->tmlx->timg_spr_tex[i]);
		i++;
	}
}
