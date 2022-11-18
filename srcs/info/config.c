/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:21:37 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/18 18:48:33 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "info.h"
#include <unistd.h>
#include <stdio.h>

t_result	validate_tex_path(char *path_ptr, t_str_buf *tex_path)
{
	int			fd;
	char		*path_raw;
	t_result	result;

	result = FAILURE;
	if (tex_path != NULL && path_ptr == NULL)
	{
		path_raw = str_dispose(str_cut(str_split(tex_path, ' ', 1), 1, BWD));
		fd = open(path_raw, O_RDONLY);
		if (fd == -1)
		{
			perror("Error: Invalid texture path");
		}
		else
		{
			path_ptr = path_raw;
			result = SUCCESS;
		}
		close(fd);
		free_safe(path_raw);
	}
	return (result);
}

t_result	init_config(t_info *info, t_str_buf *line)
{
	const char	*cardinal[CONFIG_NUM] = {"NO", "SO", "WE", "EA"};
	size_t		i;
	t_result	result;

	result = FAILURE;
	i = 0;
	while (i < CONFIG_NUM)
	{
		if (str_ncompare(line, cardinal[i], 2) == MATCH)
		{
			return (validate_tex_path(info->core.world.tex_path[i], line));
		}
		i++;
	}
	if (str_ncompare(line, "F", 1) == MATCH)
		return (parse_color(&info->core.world.rgb.floor,
				str_cut(line, 2, FWD)));
	else if (str_ncompare(line, "C", 1) == MATCH)
		return (parse_color(&info->core.world.rgb.ceiling,
				str_cut(line, 2, FWD)));
	if (result != SUCCESS)
	{
		str_free(line);
	}
	return (result);
}

bool	read_config(t_info *info)
{
	int			component;
	char		*line;
	t_str_buf	*str;

	component = 0;
	while (component != 6)
	{
		line = get_next_line(info->fd);
		if (line == NULL)
		{
			break ;
		}
		str = str_append(NULL, line);
		free_safe(line);
		component += init_config(info, str);
	}
	printf("component: %d\n", component);
	return (component == 6);
}
