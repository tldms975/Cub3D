/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:21:37 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/25 04:41:39 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "info.h"
#include <unistd.h>
#include <stdio.h>

t_result	validate_tex_path(char **path_ptr, t_str_buf *tex_path)
{
	int			fd;
	char		*path_raw;
	t_result	result;

	result = FAILURE;
	if (tex_path != NULL && *path_ptr == NULL)
	{
		path_raw = str_dispose(str_cut(str_split(tex_path, ' ', 1), 1, BWD));
		fd = open(path_raw, O_RDONLY);
		if (fd == -1)
		{
			perror("Error: Invalid texture path");
		}
		else
		{
			*path_ptr = path_raw;
			result = SUCCESS;
		}
		close(fd);
	}
	return (result);
}

t_result	init_config__texture(t_info *info, t_str_buf *line, size_t *limits)
{
	const char	*texture[] = {"NO", "SO", "WE", "EA", "DOOR"};
	size_t		i;

	i = 0;
	while (i < sizeof(texture) / sizeof(texture[0]))
	{
		if (str_ncompare(line, texture[i], 2) == MATCH)
		{
			if (i == 4)
			{
				*limits += 1;
			}
			return (validate_tex_path(&info->core.world.tex_path[i], line));
		}
		i++;
	}
	return (FAILURE);
}

t_result	init_config(t_info *info, t_str_buf *line, size_t *limits)
{
	t_result	result;

	result = init_config__texture(info, line, limits);
	if (result != SUCCESS)
	{
		if (str_ncompare(line, "F", 1) == MATCH)
		{
			return (parse_color(&info->core.world.rgb.floor,
						str_cut(line, 2, FWD)));
		}
		else if (str_ncompare(line, "C", 1) == MATCH)
		{
			return (parse_color(&info->core.world.rgb.ceiling,
						str_cut(line, 2, FWD)));
		}
		if (result != SUCCESS)
		{
			str_free(line);
		}
	}
	return (result);
}

bool	read_config(t_info *info)
{
	size_t			component;
	char		*line;
	t_str_buf	*str;
	size_t			limits;

	component = 0;
	limits = BASIC_CONFIG;
	while (component != limits)
	{
		line = get_next_line(info->fd);
		if (line == NULL)
		{
			break ;
		}
		str = str_append(NULL, line);
		free_safe(line);
		component += init_config(info, str, &limits);
	}
	printf("component: %zu\n", component);
	printf("NO: %s\n", info->core.world.tex_path[0]);
	printf("SO: %s\n", info->core.world.tex_path[1]);
	printf("WE: %s\n", info->core.world.tex_path[2]);
	printf("EA: %s\n", info->core.world.tex_path[3]);
	printf("DOOR: %s\n", info->core.world.tex_path[4]);
	return (component == limits);
}
