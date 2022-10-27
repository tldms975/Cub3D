/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:10 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 17:20:09 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"
#include "libft.h"

int	str_compare(const t_str_buf *s1, const char *s2)
{
	unsigned long	i;
	unsigned long	last_index_to_compare;

	i = 0;
	last_index_to_compare = ft_strlen(s2) - 1;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return (-1);
	while (s1->str[i] == s2[i] && s1->str[i] != '\0')
	{
		i++;
		if (i == last_index_to_compare)
		{
			break ;
		}
	}
	return ((unsigned char)s1->str[i] - (unsigned char)s2[i]);
}
