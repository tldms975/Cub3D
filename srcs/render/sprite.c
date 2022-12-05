/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:21:01 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 21:16:07 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include <math.h>
#include "sprite.h"

void	ft_draw_sprite(t_sprite *s, t_world *world)
{
	t_ivec	line;
	t_ivec	tex;

	line.x = s->dr_x.start;
	while (line.x < s->dr_x.end)
	{
		tex.x = calculate_tex_x(s, world, line);
		if (s->tr.y >= 0 && s->tr.y < world->z_buf[line.x])
		{
			line.y = s->dr_y.start;
			while (line.y < s->dr_y.end)
			{
				put_sprite(s, world, &line, &tex);
				line.y++;
			}
		}
		line.x++;
	}
}

int	*ft_get_sprite_order(t_sprite *s, int n)
{
	t_spr_arr	*arr;
	int			*ret;
	int			i;

	if (init_order(&ret, n) != 1)
	{
		init_spr_arr(s, &arr, n);
		swap_spr_arr(arr, n);
		i = 0;
		while (i < n)
		{
			ret[i] = arr[i].id;
			i++;
		}
		free(arr);
	}
	return (ret);
}

void	ft_show_sprite(t_world *world)
{
	size_t		i;
	int			*order;

	i = 0;
	while (i < world->spr_cnt)
	{
		ft_init_sprite(&world->spr[i], &world->player);
		i++;
	}
	order = ft_get_sprite_order(world->spr, world->spr_cnt);
	i = 0;
	while (i < world->spr_cnt)
	{
		ft_draw_sprite(&world->spr[order[i]], world);
		i++;
	}
	free(order);
}
