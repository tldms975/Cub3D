/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:27:47 by hdoo              #+#    #+#             */
/*   Updated: 2021/11/26 10:46:41 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_lenth;
	unsigned int	result;

	dst_lenth = ft_strlen(dst);
	if (dstsize < dst_lenth)
	{
		dst_lenth = dstsize;
	}
	result = ft_strlcpy(dst + dst_lenth, src, dstsize - dst_lenth);
	result += dst_lenth;
	return (result);
}
