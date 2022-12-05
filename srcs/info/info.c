/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:30:59 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 21:34:03 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include "info.h"
#include <stdbool.h>

t_result	read_info(t_info *info)
{
	t_result	result;

	result = FAILURE;
	if (read_config(info) == true
		&& map__read(info) == SUCCESS)
	{
		result = SUCCESS;
	}
	else
	{
		ft_putstr_fd("Error: Read_color_and_texture\n", 2);
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
		ft_putstr_fd("Error: Invalid file format\n", 2);
	}
	return (path);
}

bool	parse_dot_cub(t_info *info, char *arg)
{
	bool	retval;

	retval = FAILURE;
	info->cub_path = validate_path(arg);
	if (info->cub_path != NULL)
	{
		info->fd = str_safe_open(info->cub_path, O_RDONLY);
		if (info->fd != -1 && read_info(info) == SUCCESS)
		{
			retval = true;
		}
		else
		{
			ft_putstr_fd("Error: Read_info\n", 2);
		}
	}
	return (retval);
}
