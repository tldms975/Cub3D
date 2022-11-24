/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:01:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/25 04:46:57 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "types/t_mlx.h"
#include <math.h>

int	ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	dr->tex.y = (int)tex->pos & (world->tmlx->timg_texture[tex->type].h - 1);
	tex->pos += tex->step;
	color = world->texture[tex->type] \
	[(int)(world->tmlx->timg_texture[tex->type].h * dr->tex.y + dr->tex.x)];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}


void	ft_wear_texture(t_world *world, t_raycast *rc, t_texture *tex, \
t_draw *dr)
{
	tex->wall_x -= floor(tex->wall_x);
	dr->tex.x \
	= (int)(tex->wall_x * (double)world->tmlx->timg_texture[tex->type].w);
	if ((rc->is_side == 0 && rc->ray.x > 0) \
	|| (rc->is_side == 1 && rc->ray.y < 0))
		dr->tex.x = world->tmlx->timg_texture[tex->type].w - dr->tex.x - 1;
	tex->step = 1.0 * world->tmlx->timg_texture[tex->type].h / dr->line_h;
	tex->pos \
	= (dr->start - world->screen_h / 2.0 + dr->line_h / 2.0) * tex->step;
}

int	*ft_load_image(char *path, t_mlx *tmlx, int i)
{
	int	*res;
	int	y;
	int	x;

	tmlx->timg_texture[i].img = mlx_xpm_file_to_image(tmlx->mlx, path, \
	&tmlx->timg_texture[i].w, &tmlx->timg_texture[i].h);
	tmlx->timg_texture[i].data \
	= (int *)mlx_get_data_addr(tmlx->timg_texture[i].img, \
	&tmlx->timg_texture[i].bpp, &tmlx->timg_texture[i].line_len, \
	&tmlx->timg_texture[i].endian);
	res = (int *)malloc(sizeof(int) \
	* (tmlx->timg_texture[i].w * tmlx->timg_texture[i].h));
	y = -1;
	while (++y < tmlx->timg_texture[i].h)
	{
		x = -1;
		while (++x < tmlx->timg_texture[i].w)
		{
			res[tmlx->timg_texture[i].w * y + x] \
			= tmlx->timg_texture[i].data[tmlx->timg_texture[i].w * y + x];
		}
	}
	mlx_destroy_image(tmlx->mlx, tmlx->timg_texture[i].img);
	return (res);
}

void	ft_load_texture(t_info *info)
{
	t_world	*world;
	int		i;

	world = &info->core.world;
	i = 0;
	while (i < 5)
	{
		world->texture[i] = ft_load_image(world->tex_path[i], world->tmlx, i);
		i++;
	}
}
