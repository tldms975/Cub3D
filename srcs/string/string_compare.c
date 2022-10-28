/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:10 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/28 17:33:41 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"
#include "libft.h"

int	str_compare(const t_str_buf *s1, const char *s2)
{
	unsigned long	i;

	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return (-1);
	while (s1->str[i] == s2[i] && s1->str[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1->str[i] - (unsigned char)s2[i]);
}

int	str_ncompare(const t_str_buf *s1, const char *s2, int n)
{
	unsigned long	i;
	unsigned long	uln;

	i = 0;
	if (n < 0)
	{
		n *= -1;
	}
	uln = (unsigned long)n;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return (-1);
	while (s1->str[i] == s2[i] && s1->str[i] != '\0')
	{
		if (i == uln)
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1->str[uln] - (unsigned char)s2[uln]);
}
