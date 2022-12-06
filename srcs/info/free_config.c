/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:07:11 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/06 22:09:03 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include <stdio.h>

void	free_config(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->core.world.wall_tex_n && i < 5)
	{
		if (info->core.world.tex_path[i] != NULL)
		{
			free_safe(info->core.world.tex_path[i]);
			info->core.world.tex_path[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < info->core.world.spr_tex_cnt)
	{
		if (info->core.world.spr_tex_path[i] != NULL)
		{
			free_safe(info->core.world.spr_tex_path[i]);
			info->core.world.spr_tex_path[i] = NULL;
		}
		i++;
	}
}
