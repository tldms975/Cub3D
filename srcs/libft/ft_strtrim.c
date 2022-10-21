/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:47:53 by hdoo              #+#    #+#             */
/*   Updated: 2022/03/06 10:00:28 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	char_is_in_set(char const c, char const *set);
static int	end_i(char const *s1, char const *set);
static int	start_i(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*result;

	if (s1 == NULL)
		return (NULL);
	if (end_i(s1, set) >= start_i(s1, set))
	{
		result = ft_substr(s1, start_i(s1, set), \
				(end_i(s1, set) - start_i(s1, set) + 1));
		if (result == NULL || (end_i(s1, set) - start_i(s1, set) + 1) == 0)
			return (NULL);
	}
	else
	{
		return (ft_strdup(""));
	}
	return (result);
}

static int	char_is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start_i(char const *s1, char const *set)
{
	int		start_newstr;

	start_newstr = 0;
	while (char_is_in_set(s1[start_newstr], set) == 1)
		start_newstr++;
	return (start_newstr);
}

static int	end_i(char const *s1, char const *set)
{
	int		end_newstr;

	end_newstr = ft_strlen((char *)s1) - 1;
	while (char_is_in_set(s1[end_newstr], set) == 1)
	{
		end_newstr--;
		if (end_newstr == 0)
			break ;
	}
	return (end_newstr);
}
