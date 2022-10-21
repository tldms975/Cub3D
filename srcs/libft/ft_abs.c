/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:14:55 by hdoo              #+#    #+#             */
/*   Updated: 2022/05/14 14:11:55 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_abs(int target)
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
