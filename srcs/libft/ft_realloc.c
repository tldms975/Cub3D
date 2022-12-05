/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:48:59 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 15:42:25 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size,
		const size_t old_size, size_t *size_ptr)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (size != 0)
	{
		while (size < old_size)
		{
			size *= 2;
		}
		new_ptr = malloc_safe(size);
		if (ptr != NULL)
		{
			ft_memcpy(new_ptr, ptr, old_size);
			free_safe(ptr);
		}
		if (size_ptr != NULL)
		{
			*size_ptr = size;
		}
	}
	return (new_ptr);
}
