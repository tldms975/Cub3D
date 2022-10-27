/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 16:06:46 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_string.h"

t_string	new_str(char *target);

t_string	new_str(char *target)
{
	t_string	new_string;

	new_string.len = ft_strlen(target);
	new_string.content = malloc(new_string.len);

	return (new_string);
}
