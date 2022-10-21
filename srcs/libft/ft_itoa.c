/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:42:33 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/09 12:57:49 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			count_digit(int n);
static unsigned	int	convert_sign(int n, char *result);
static void			append_int_to_str(char *result, unsigned int n, int digit);

char	*ft_itoa(int n)
{
	unsigned int	unsigned_n;
	char			*result;
	int				digit;

	digit = count_digit(n);
	result = malloc(sizeof(char) * (digit + 1));
	if (result == NULL)
		return (NULL);
	unsigned_n = convert_sign(n, result);
	append_int_to_str(result, unsigned_n, digit);
	result[digit] = '\0';
	return (result);
}

static int	count_digit(int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
		digit = 2;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			digit++;
	}
	return (digit);
}

static unsigned int	convert_sign(int n, char *result)
{
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	return ((unsigned)n);
}

static void	append_int_to_str(char *result, unsigned int n, int digit)
{	
	int	index;

	index = digit - 1;
	if (n != 0)
	{
		while (n > 0)
		{
			result[index] = (n % 10) + '0';
			index--;
			n /= 10;
		}
	}
	else
	{
		result[0] = '0';
	}
}
