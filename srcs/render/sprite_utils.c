/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:13:58 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 21:15:37 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_sprite(t_sprite *s, t_world *world, t_ivec *line, t_ivec *tex)
{
	int		d;
	int		color;
	size_t	frame;

	frame = world->frame / ANI_SPEED;
	d = (line->y - s->v_move_screen) * 256 - WIN_H * 128 + s->h * 128;
	tex->y = ((d * world->tmlx->timg_spr_tex[frame].h) / s->h) / 256;
	color = world->spr_tex[frame][world->tmlx->timg_spr_tex[frame].w
		* tex->y + tex->x];
	if ((color & 0x00FFFFFF) != 0)
	{
		world->screen_buf[line->y][line->x] = color;
	}
}

int	calculate_tex_x(t_sprite *s, t_world *world, t_ivec line)
{
	int	result;

	result = 256;
	result *= (line.x - (-s->w / 2 + s->screen_x));
	result *= world->tmlx->timg_spr_tex[world->frame / ANI_SPEED].w;
	result /= s->w;
	result /= 256;
	return (result);
}

void	ft_swap(t_spr_arr *a, t_spr_arr *b)
{
	t_spr_arr	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_spr_arr(t_spr_arr *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i].d < arr[j].d)
			{
				ft_swap(&arr[i], &arr[j]);
				break ;
			}
			j++;
		}
		i++;
	}
}
