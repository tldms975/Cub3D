/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:21:37 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/04 16:37:43 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "info.h"
#include "libft.h"
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
			result = ERROR;
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
		if (str_ncompare(line, texture[i], ft_strlen(texture[i])) == MATCH)
		{
			if (i >= 4)
			{
				*limits += 1;
			}
			return (validate_tex_path(&info->core.world.tex_path[i], line));
		}
		if (str_ncompare(line, "SPRITE", 6) == MATCH)
		{
			*limits += 1;
			return (validate_tex_path(
					&info->core.world.spr_tex_path[
						info->core.world.spr_tex_cnt++], line));
		}
		i++;
	}
	return (FAILURE);
}

t_result	init_config(t_info *info, char *line, size_t *limits)
{
	t_result	result;
	t_str_buf	*str;

	str = str_append(NULL, line);
	free_safe(line);
	result = init_config__texture(info, str, limits);
	if (result == FAILURE)
	{
		if (str_ncompare(str, "F", 1) == MATCH)
		{
			return (parse_color(&info->core.world.rgb.floor,
					str_cut(str, 2, FWD)));
		}
		else if (str_ncompare(str, "C", 1) == MATCH)
		{
			return (parse_color(&info->core.world.rgb.ceiling,
					str_cut(str, 2, FWD)));
		}
		if (result != SUCCESS)
		{
			str_free(str);
		}
	}
	return (result);
}

bool	read_config(t_info *info)
{
	size_t			component;
	char			*line;
	size_t			limits;
	t_result		result;

	component = 0;
	limits = BASIC_CONFIG;
	while (component != limits)
	{
		line = get_next_line(info->fd);
		if (line == NULL)
		{
			break ;
		}
		result = init_config(info, line, &limits);
		if (result == ERROR)
		{
			ft_putstr_fd("Error: read_config\n", 2);
			return (false);
		}
		component += result;
	}
	return (component == limits);
}
