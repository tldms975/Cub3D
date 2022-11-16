/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:11:15 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 19:06:51 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include <sys/fcntl.h>

void	map__free_redzone(t_info *info)
{
	size_t	i;

	if (info->map.redzone != NULL)
	{
		i = 0;
		while (i < info->map.height + 2)
		{
			free_safe(info->map.redzone[i]);
			i++;
		}
		free_safe(info->map.redzone);
	}
	info->map.redzone = NULL;
}

void	map__free_visited(t_info *info)
{
	size_t	i;

	if (info->map.visited != NULL)
	{
		i = 0;
		while (i < info->map.height)
		{
			free_safe(info->map.visited[i]);
			i++;
		}
		free_safe(info->map.visited);
	}
	info->map.visited = NULL;
}

void	map__free_open_path(t_path *open)
{
	if (open->path != NULL)
	{
		free_safe(open->path);
		open->path = NULL;
	}
}
