/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:27:21 by hdoo              #+#    #+#             */
/*   Updated: 2021/11/22 13:56:23 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		char_c;
	const char	*last_match;

	char_c = (char)c;
	last_match = NULL;
	while (*s != '\0')
	{
		if (*s == char_c)
			last_match = s;
		s++;
	}
	if (c != '\0')
		return ((char *)last_match);
	else
		return ((char *)s);
}
