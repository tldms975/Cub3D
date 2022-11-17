/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:10 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 16:56:59 by hdoo             ###   ########.fr       */
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

int	str_ncompare(const t_str_buf *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (s1->str[j] != s2[i++])
			return ((unsigned char)s1->str[j] - (unsigned char)s2[--i]);
		if (s1->str[j++] == 0)
			break ;
		n--;
	}
	return (0);
}
