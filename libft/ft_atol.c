/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:26:31 by hdoo              #+#    #+#             */
/*   Updated: 2022/06/11 00:54:34 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_sign(char c);
static void	skip_extra(const char **str);

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	skip_extra(&str);
	if (*str == '-' || *str == '+')
		sign = convert_sign(*str++);
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (sign * result);
}

static int	convert_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

static void	skip_extra(const char **str)
{
	if (**str == '\0')
		return ;
	while (**str == '\t' || \
		**str == '\n' || \
		**str == '\v' || \
		**str == '\f' || \
		**str == '\r' || \
		**str == ' ')
		(*str)++;
}
