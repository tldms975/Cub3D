/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/10/27 18:41:02 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fcntl.h"
#include "unistd.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include "libft.h"
#include "string_buffer.h"
#include "cub3d.h"

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
	return (path);
}

int ft_open(t_str_buf *path, int oflag)
{
	int fd;

	fd = open(path->str, oflag);
	if (fd == -1)
	{
		perror("Error: fail to open with given path: ");
		exit(2);
	}
	return (fd);
}

int	init_info(t_info *info, t_str_buf *line)
{

	if (str_compare(line, "NO"))
	{
		str_cut(line, 3, 1);
		info->core.world.fd_texture[NO] = ft_open(line, O_RDONLY);
	}

}

bool	read_color_and_texture(t_info *info)
{
	bool		result;
	int			component;
	t_str_buf	*line;

	component = 0;
	while (component != 6)
	{
		line = str_append(NULL, get_next_line(info->fd));
		init_info(info, line);

	}

	return ()
}

bool	read_info(t_info *info)
{
	read_color_and_texture(info);
	read_map(info);


}

bool	parse_info(t_info *info, char* argv[])
{
	bool	retval;

	retval = false;
	info->path = validate_path(argv);
	if (info->path->str != NULL)
	{
		info->fd = ft_open(info->path, O_RDONLY);
		if (read_info(info) != -1 && \

				)
		{


		}
	}
	return (retval);
}

int	main(int argc, char* argv[])
{
	t_info	info;

	if (argc == 2)
	{
		if (parse_info(&info, argv))
		{

		}
	}
	else
	{
		printf("Wrong number of arguments: expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
