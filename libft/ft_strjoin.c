/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 07:20:28 by hdoo              #+#    #+#             */
/*   Updated: 2022/03/02 11:14:35 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	strcpy_till_end(char *str, char *target);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		newstr_len;
	int		copied_lenth;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstr_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = malloc(sizeof(char) * (newstr_len + 1));
	if (newstr == NULL)
		return (NULL);
	copied_lenth = strcpy_till_end(s1, newstr);
	copied_lenth += strcpy_till_end(s2, (newstr + copied_lenth));
	newstr[copied_lenth] = '\0';
	return (newstr);
}

static int	strcpy_till_end(char *str, char *target)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		target[i] = str[i];
		i++;
	}
	return (i);
}
