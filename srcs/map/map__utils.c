/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map__utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:04 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 15:59:45 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

char	map__check_char(char target)
{
	size_t		i;
	const char	valid_char[]
		= {'\n', ' ', '0', '1', 'D', 'N', 'S', 'W', 'E'};

	i = 0;
	while (i < sizeof(valid_char))
	{
		if (valid_char[i] == target)
		{
			return (valid_char[i]);
		}
		i++;
	}
	return (FAILURE);
}
