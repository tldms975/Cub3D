/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:30:59 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 01:15:28 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "colors.h"
#include "map.h"
#include "string_buffer.h"
#include <stdio.h> // TOOD - remove
#include <sys/fcntl.h>

int	init_texture_and_color(t_info *info, t_str_buf *line)
{
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

bool	read_color_and_texture(t_info *info)
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
		component += init_texture_and_color(info, str);
	}
	return (component == 6);
}

t_result	read_info(t_info *info)
{
	if (read_color_and_texture(info) == true)
	{
		printf("NO:%s", info->core.world.txr[NO]);
		printf("SO:%s", info->core.world.txr[SO]);
		printf("WE:%s", info->core.world.txr[WE]);
		printf("EA:%s", info->core.world.txr[EA]);
		printf("f: T: %d R:%d G:%d B:%d\n", \
				get_t(info->core.world.floor.rgb), \
				get_r(info->core.world.floor.rgb), \
				get_g(info->core.world.floor.rgb), \
				get_b(info->core.world.floor.rgb));
		printf("c: T: %d R:%d G:%d B:%d\n", \
				get_t(info->core.world.ceiling.rgb), \
				get_r(info->core.world.ceiling.rgb), \
				get_g(info->core.world.ceiling.rgb), \
				get_b(info->core.world.ceiling.rgb));
		read_map(info);
	}
	else
	{
		printf("failed: read_color_and_texture\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

t_str_buf	*validate_path(char *argv[])
{
	t_str_buf	*path;
	int			len;

	path = NULL;
	len = ft_strlen(argv[1]);
	if (len >= 4 && \
		argv[1][len - 4] == '.' && \
		argv[1][len - 3] == 'c' && \
		argv[1][len - 2] == 'u' && \
		argv[1][len - 1] == 'b')
	{
		path = str_append(NULL, argv[1]);
	}
	else
	{
		printf("failed: invalid file format\n");
	}
	return (path);
}

bool	parse_dot_cub(t_info *info, char* argv[])
{
	bool	retval;

	retval = FAILURE;
	info->path = validate_path(argv);
	if (info->path->str != NULL)
	{
		info->fd = str_safe_open(info->path, O_RDONLY);
		if (read_info(info) == SUCCESS)
		{
			retval = true;
		}
		else
		{
			printf("failed: read_info\n");
		}
	}
	return (retval);
}

