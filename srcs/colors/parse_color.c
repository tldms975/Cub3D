/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:28:18 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 21:34:01 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include <stdio.h>

t_result	extract_color(char **colors, int *raw_color)
{
	int			i;
	t_result	result;

	result = SUCCESS;
	i = 0;
	while (i < 3 && colors[i] != NULL)
	{
		raw_color[i] = ft_atoi(colors[i]);
		i++;
	}
	if (i != 3)
	{
		ft_putstr_fd("Error: Not enough color\n", 2);
		result = ERROR;
	}
	else if (raw_color[0] > 255 || raw_color[1] > 255 || raw_color[2] > 255)
	{
		ft_putstr_fd("Error: Color out of range\n", 2);
		result = ERROR;
	}
	return (result);
}

t_result	parse_color(int *color, t_str_buf *line)
{
	int			raw_color[3];
	char		*line_char;
	char		**colors;
	t_result	result;

	line_char = str_dispose(line);
	colors = ft_split(line_char, ',');
	result = FAILURE;
	if (colors != NULL && color != NULL)
	{
		result = extract_color(colors, raw_color);
		if (result == SUCCESS)
		{
			*color = create_trgb(0, raw_color[0], raw_color[1], raw_color[2]);
		}
		ft_free_split(colors);
		free_safe(line_char);
	}
	else if (colors == NULL)
	{
		printf("Error: Parse_color: split returned null\n");
		result = ERROR;
	}
	return (result);
}
