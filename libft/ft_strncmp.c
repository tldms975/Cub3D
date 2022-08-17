/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:27:40 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/01 21:07:03 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned long	last_index_to_compare;

	i = 0;
	last_index_to_compare = n - 1;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
		if (i == last_index_to_compare)
		{
			break ;
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
