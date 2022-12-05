/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:07:04 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 16:12:28 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/t_world.h"
#include "minimap.h"
#include "colors.h"

void	set_minimap_color(t_minimap_color *color)
{
	color->bg = create_trgb(255, 0, 0, 0);
	color->fg = create_trgb(100, 90, 102, 70);
	color->wl = create_trgb(100, 198, 210, 202);
	color->dr = create_trgb(100, 166, 123, 91);
	color->sp = create_trgb(200, 16, 23, 91);
}

void	put_color(t_info *info, size_t x, size_t y, t_minimap_color color)
{
	if (info->core.world.map[y][x] == '1')
		ft_fill_miniimap_block(info, y, x, color.fg);
	else if (info->core.world.map[y][x] == 'D')
		ft_fill_miniimap_block(info, y, x, color.dr);
	else if (info->core.world.map[y][x] == 'T')
		ft_fill_miniimap_block(info, y, x, color.sp);
	else if (info->core.world.map[y][x] == ' '
			|| info->core.world.map[y][x] == '\n')
		ft_fill_miniimap_block(info, y, x, color.bg);
	else
		ft_fill_miniimap_block(info, y, x, color.wl);
}
