/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:27:01 by hdoo              #+#    #+#             */
/*   Updated: 2022/05/12 16:26:05 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_sign(char c);
static void	skip_extra(const char **str);
static int	result_overflow(int sign);

int	ft_atoi(const char *str)
{
	int64_t	result;
	int		sign;

	result = 0;
	sign = 1;
	skip_extra(&str);
	if (*str == '-' || *str == '+')
		sign = convert_sign(*str++);
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		result *= 10;
		result += (*str - '0');
		if (result * sign < INT32_MIN || result * sign > INT32_MAX)
			return (result_overflow(sign));
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

static int	result_overflow(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}
