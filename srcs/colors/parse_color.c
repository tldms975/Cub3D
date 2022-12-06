/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:28:18 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/06 19:19:03 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include <stdio.h>

int	atoi_precheck(char *target)
{
	int	i;

	i = 0;
	if (target[i] == '-')
	{
		i++;
	}
	while (target != NULL
		&& target[i] != '\0'
		&& target[i] != '\n')
	{
		if (ft_isdigit(target[i]) != 1)
		{
			ft_putstr_fd("Error: Ivalid input: Not an integer", 2);
		}
		i++;
	}
	return (target[i] == '\0' || target[i] == '\n');
}

t_result	atoi_postcheck(int result, char *origin)
{
	if ((result == 0 && origin[0] != '0')
		|| (result == -1 && !(origin[0] == '-' && origin[1] == '1')))
	{
		ft_putstr_fd("Error: Color input overflowed\n", 2);
		return (ERROR);
	}
	else if (result < 0)
	{
		ft_putstr_fd("Error: Color out of range: Minus value\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_result	strict_atoi(char **colors, int *raw_color, int i)
{
	if (atoi_precheck(colors[i]) == SUCCESS)
	{
		raw_color[i] = ft_atoi(colors[i]);
		if (atoi_postcheck(raw_color[i], colors[i]) == SUCCESS)
		{
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

t_result	extract_color(char **colors, int *raw_color)
{
	int			i;
	t_result	result;

	result = FAILURE;
	i = 0;
	while (i < 3 && colors[i] != NULL)
	{
		result = strict_atoi(colors, raw_color, i);
		if (result != SUCCESS)
		{
			break ;
		}
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
