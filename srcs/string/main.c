/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:02:50 by sielee            #+#    #+#             */
/*   Updated: 2022/10/24 04:45:39 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fcntl.h"
#include "unistd.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include "libft.h"
// #include "cub3d.h"

typedef struct s_info
{
	char	**map;
}	t_info;

char	*check_name(char *argv[])
{
	char	*name;

	name = argv[1];
	return (name);
}

bool	parse_info(t_info *info, char* argv[])
{
	int	fd;
	bool	retval;
	char	*name;

	retval = false;
	name = check_name(argv);
	fd = open(name, 0644);
	info->map[0] = get_next_line(fd);
	return (retval);
}

int	main(int argc, char* argv[])
{
	t_info	info;

	if (argc == 2)
	{
		parse_info(&info, argv);

	}
	else
	{
		printf("Wrong number of arguments: expected 1, but get %d\n", (argc - 1));
	}
	return (0);
}
