/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:07:11 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 20:47:32 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	free_config(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (info->core.world.tex_path[i] != NULL)
		{
			free_safe(info->core.world.tex_path[i]);
			info->core.world.tex_path[i] = NULL;
		}
		i++;
	}
}
