/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:45:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/10 18:56:45 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"

char **str_split(const char *target, const char del, const int delcount)
{
	int		word_i;
	int		char_i;
	char	**result;

	result = malloc_safe(sizeof(char *) * (delcount + 1));
	word_i = 0;
	while (word_i < delcount)
	{
		char_i = 0;
		while (target[char_i] != '\0' && target[char_i] != del)
		{
			char_i++;
		}
		if (target[char_i] )
		{

		}
		word_i++;
	}
	return (result);
}
