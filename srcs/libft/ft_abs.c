/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:14:55 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/12 04:03:31 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_abs(int target)
{
	if (target >= 0)
	{
		return ((unsigned)target);
	}
	else
	{
		return ((unsigned)(target * -1));
	}
}
