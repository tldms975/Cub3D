/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:30:59 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/12 03:12:26 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "colors.h"
#include "map.h"
#include "string_buffer.h"
#include <stdbool.h>
#include <stdio.h> // TOOD - remove
#include <sys/fcntl.h>

int	init_config(t_info *info, t_str_buf *line)
{
	// TODO -- change cut to split to handle spaces
	if (str_ncompare(line, "NO", 2) == MATCH)
		info->core.world.txr[NO] = str_dispose(str_cut(line, 3, FWD));
	else if (str_ncompare(line, "SO", 2) == MATCH)
		info->core.world.txr[SO] = str_dispose(str_cut(line, 3, FWD));
	else if (str_ncompare(line, "WE", 2) == MATCH)
		info->core.world.txr[WE] = str_dispose(str_cut(line, 3, FWD));
	else if (str_ncompare(line, "EA", 2) == MATCH)
		info->core.world.txr[EA] = str_dispose(str_cut(line, 3, FWD));
	else if (str_ncompare(line, "F", 1) == MATCH)
		parse_color(&info->core.world.floor.rgb, str_cut(line, 2, FWD));
	else if (str_ncompare(line, "C", 1) == MATCH)
		parse_color(&info->core.world.ceiling.rgb, str_cut(line, 2, FWD));
	else
	{
		free_safe(str_dispose(line));
		return (0);
	}
	return (1);
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
	return (component == 6);
}

t_result	read_info(t_info *info)
{
	t_result result;

	result = FAILURE;
	if (read_config(info) == true
			&& map__read(info) == SUCCESS)
	{
		result = SUCCESS;
	}
	else
	{
		printf("Error: read_color_and_texture\n");
	}
	return (result);
}

static t_str_buf	*validate_path(char *arg)
{
	t_str_buf	*path;
	int			len;

	path = NULL;
	len = ft_strlen(arg);
	if (len >= 4 && \
		arg[len - 4] == '.' && \
		arg[len - 3] == 'c' && \
		arg[len - 2] == 'u' && \
		arg[len - 1] == 'b')
	{
		path = str_append(NULL, arg);
	}
	else
	{
		printf("Error: invalid file format\n");
	}
	return (path);
}

bool	parse_dot_cub(t_info *info, char* arg)
{
	bool	retval;

	retval = FAILURE;
	info->path = validate_path(arg);
	if (info->path->str != NULL)
	{
		info->fd = str_safe_open(info->path, O_RDONLY);
		if (read_info(info) == SUCCESS)
		{
			retval = true;
		}
		else
		{
			printf("Error: read_info\n");
		}
	}
	return (retval);
}
