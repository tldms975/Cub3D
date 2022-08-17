/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:26:47 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/02 15:06:05 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*result;
	size_t		i;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
		result[i++] = 0;
	return (result);
}
