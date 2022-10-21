/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:28:16 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/01 20:27:21 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		((unsigned char *)ptr)[i++] = value;
	return (ptr);
}
