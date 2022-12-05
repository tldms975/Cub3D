/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:48:52 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 15:53:20 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ft_change_map_format(t_info *info)
{
	size_t	i;

	info->core.world.map = malloc_safe(sizeof(char *) * info->map.height);
	i = 0;
	while (i < info->map.height)
	{
		info->core.world.map[i] = malloc_safe(sizeof(char) * info->map.width);
		ft_memset(info->core.world.map[i], ' ', info->map.width);
		ft_memcpy(info->core.world.map[i], info->map.raw[i]->str,
			info->map.raw[i]->length);
		i++;
	}
}

void	ft_create_minimap_buf(t_info *info)
{
	size_t	i;

	info->core.world.minimap_w = ceil((double)info->map.width * 8);
	info->core.world.minimap_h = ceil((double)info->map.height * 8);
	info->core.world.minimap_buf
		= malloc(sizeof(int *) * (info->core.world.minimap_h));
	i = 0;
	while (i < info->core.world.minimap_h)
	{
		info->core.world.minimap_buf[i]
			= malloc(sizeof(int) * (info->core.world.minimap_w));
		ft_memset(info->core.world.minimap_buf[i],
			0, sizeof(int) * (info->core.world.minimap_w));
		i++;
	}
}

void	set_screen_size(t_info *info)
{
	info->core.world.screen_w = WIN_W;
	info->core.world.screen_h = WIN_H;
	info->mousecode = info->core.world.screen_w / 2;
}

void	ft_create_screen_buf(t_info *info)
{
	size_t	i;

	info->core.world.screen_buf = malloc_safe(sizeof(int *) \
	* info->core.world.screen_h);
	i = 0;
	while (i < info->core.world.screen_h)
	{
		info->core.world.screen_buf[i] = malloc_safe(sizeof(int) \
		* info->core.world.screen_w);
		ft_memset(info->core.world.screen_buf[i], 0, sizeof(int) \
		* info->core.world.screen_w);
		i++;
	}
}
