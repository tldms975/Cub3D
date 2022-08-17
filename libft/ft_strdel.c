/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 06:53:22 by hdoo              #+#    #+#             */
/*   Updated: 2022/05/11 07:22:31 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **splited_str)
{
	int	i;

	i = 0;
	while (splited_str[i] != NULL)
	{
		free(splited_str[i]);
		i++;
	}
	free(splited_str);
}
