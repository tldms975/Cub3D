/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/10/27 16:40:18 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fcntl.h"
#include "unistd.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include "libft.h"
#include "ft_string.h"
// #include "cub3d.h"

typedef struct s_info
{
	t_string path;
	char	**map;
	int		fd;
}	t_info;

t_string	validate_path(char *argv[])
{
	t_string path;
	int len;

	path.content = NULL;
	len = strlen(argv[1]);
	if (len - 2 > 0 && \
		argv[1][len - 4] == '.' && \
		argv[1][len - 3] == 'c' && \
		argv[1][len - 2] == 'u' && \
		argv[1][len - 1] == 'b')
	{
		path.content = strdup(argv[1]);
		path.len = len;
		path.size = len;
	}
	return (path);
}

int ft_open(t_string path, int oflag)
{
	int fd;

	fd = open(path.content, oflag);
	if (fd == -1)
	{
		perror("Error: fail to open with given path: ");
		exit(2);
	}
}

bool	read_info(t_info *info)
{
	char **line;

	while (1)
	{
		line = ft_split(get_next_line(info->fd), ' ');
		
	}

}


bool	parse_info(t_info *info, char* argv[])
{
	bool	retval;

	retval = false;
	info->path = validate_path(argv);
	if (info->path.content != NULL)
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
