/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 16:21:17 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "string_buffer.h"

t_str_buf	*new_str(char *target);

t_str_buf	*new_str(char *target)
{
	t_str_buf	*new_string = NULL;

	new_string->length = ft_strlen(target);
	new_string->str = malloc(new_string->length);
	new_string->capacity = new_string->length;
	return (new_string);
}
