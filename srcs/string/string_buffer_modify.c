/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_modify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 18:01:30 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "safe_mem.h"
#include "string_buffer.h"

/**
 * @brief cut string by given int n, if positive, cut from begin. if negative, cut from end.
 *
 * @param buf buffer that will be cutted.
 * @param n number of character that cut from buf.
 * @return new buf that cutted
 */
t_str_buf	*str_cut(t_str_buf *buf, size_t n, bool dir)
{
	t_str_buf	*new_str;

	if (buf->length <= n)
	{
		free_safe(buf->str);
		free_safe(buf);
		return (NULL);
	}
	new_str = malloc_safe(sizeof(*new_str));
	new_str->length = buf->length - n;
	new_str->str = malloc(sizeof(char) * (new_str->length));
	new_str->capacity = new_str->length;
	ft_memcpy(new_str->str, buf->str + (n * dir), new_str->length);
	str_free(buf);
	return (new_str);
}
