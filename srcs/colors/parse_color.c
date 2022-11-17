/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:28:18 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 19:46:52 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include <stdio.h>

t_result	parse_color(int *color, t_str_buf *line)
{
	char		*line_char;
	char		**colors;

	line_char = str_dispose(line);
	colors = ft_split(line_char, ',');
	if (colors != NULL && color != NULL)
	{
		*color = create_trgb(0,
				ft_atoi(colors[0]),
				ft_atoi(colors[1]),
				ft_atoi(colors[2]));
		ft_free_split(colors);
		free_safe(line_char);
		return (SUCCESS);
	}
	else if (colors == NULL)
	{
		printf("failed: parse_color: split returned null\n");
		return (ERROR);
	}
	return (FAILURE);
}
