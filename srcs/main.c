/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/10/29 05:47:42 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include "safe_mem.h"
#include "string_buffer.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdbool.h>

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
		printf("failed: validate_path\n");
	}
	return (path);
}

int ft_open(t_str_buf *path, int oflag)
{
	int fd;

	fd = open(str_dispose(path), oflag);
	if (fd == -1)
	{
		perror("Error: fail to open with given path: \n");
		exit(2);
	}
	return (fd);
}

void	parse_color(t_rgb *color, t_str_buf *line)
{
	char	*line_char;
	char	**colors;

	line_char = str_dispose(line);
	colors = ft_split(line_char, ',');
	if (colors != NULL && color != NULL)
	{
		color->r = ft_atoi(colors[0]);
		color->g = ft_atoi(colors[1]);
		color->b = ft_atoi(colors[2]);
		ft_free_split(colors);
		free_safe(line_char);
	}
	else
	{
		if (color == NULL)
		{
			printf("failed: parse_color: color is null\n");
		}
		else if (colors == NULL)
		{
			printf("failed: parse_color: split returned null\n");
		}
	}
}

int	init_info(t_info *info, t_str_buf *line)
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
			break;
		}
		str = str_append(NULL, line);
		free_safe(line);
		component += init_info(info, str);
	}
	return (component == 6);
}

void	*realloc_map_raw_data(t_info *info)
{
	t_str_buf	**new_map;
	size_t		old_capacity;

	new_map = info->map.raw_data;
	old_capacity = info->map.capacity;
	if (info->map.capacity <= info->map.height)
	{
		info->map.capacity *= 2;
	}
	new_map = malloc_safe(sizeof(t_str_buf *) * (info->map.capacity));
	if (info->map.raw_data != NULL)
	{
		ft_memcpy(new_map, info->map.raw_data, sizeof(t_str_buf *) * old_capacity);
		free_safe(info->map.raw_data);
	}
	return (new_map);
}

void	print_map(t_info *info, size_t x, size_t y)
{
	(void)x;
	for (size_t i = 0; i < info->map.height; i++)
	{
		if (i == y)
		{
			for (size_t j = 0; j < info->map.raw_data[y]->length; j++)
			{
				if (j == x)
				{
					printf("%s%c%s", RED, 'X', NOCOLOR);
				}
				else
					printf("%c", info->map.raw_data[y]->str[j]);
			}
		}
		else
			printf("%s", str_dispose(info->map.raw_data[i]));
	}
}

t_result	scan_map(t_info *info)
{
	char		*line;
	t_str_buf	*new_row;

	line = get_next_line(info->fd);
	info->map.capacity = 1;
	while (line != NULL)
	{
		info->map.raw_data = (t_str_buf **)realloc_map_raw_data(info);
		new_row = str_append(NULL, line);
		info->map.raw_data[info->map.height++] = new_row;
		if (info->map.width < new_row->length)
		{
			info->map.width = new_row->length;
		}
		line = get_next_line(info->fd);
	}
	// print_map(info, );
	return (SUCCESS);
}

t_result	read_map(t_info *info)
{
	if (scan_map(info) == SUCCESS && \
			validate_map(info) == SUCCESS)
	{
		return (SUCCESS);
	}
	return (FAILURE);
}

t_result	read_info(t_info *info)
{
	if (read_color_and_texture(info) == true)
	{
		printf("NO:%s", info->core.world.txr[NO]);
		printf("SO:%s", info->core.world.txr[SO]);
		printf("WE:%s", info->core.world.txr[WE]);
		printf("EA:%s", info->core.world.txr[EA]);
		printf("f: R:%d G:%d B:%d\n", \
				info->core.world.floor.rgb.r, \
				info->core.world.floor.rgb.g, \
				info->core.world.floor.rgb.b);
		printf("c: R:%d G:%d B:%d\n", \
				info->core.world.ceiling.rgb.r, \
				info->core.world.ceiling.rgb.g, \
				info->core.world.ceiling.rgb.b);
		read_map(info);
	}
	else
	{
		printf("failed: read_color_and_texture\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

bool	parse_dot_cub(t_info *info, char* argv[])
{
	bool	retval;

	retval = FAILURE;
	info->path = validate_path(argv);
	if (info->path->str != NULL)
	{
		info->fd = ft_open(info->path, O_RDONLY);
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

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		ft_memset(&info, 0, sizeof(t_info));
		if (parse_dot_cub(&info, argv) == SUCCESS)
		{
			printf("failed: parse_dot_cub\n");
		}
	}
	else
	{
		printf("Wrong number of arguments: expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
