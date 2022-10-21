/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:25:31 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/07 21:49:38 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*unsigned_char_s;
	unsigned char	unsigned_char_c;

	i = 0;
	unsigned_char_s = (unsigned char *)s;
	unsigned_char_c = (unsigned char)c;
	while (i < n)
	{
		if (unsigned_char_s[i] == unsigned_char_c)
		{
			return (unsigned_char_s + i);
		}
		i++;
	}	
	return (NULL);
}
