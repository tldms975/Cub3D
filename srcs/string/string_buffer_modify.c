/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_modify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 04:47:52 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string_buffer.h"
#include "libft.h"

/**
 * @brief cut string by given int n, if positive, cut from begin. if negative, cut from end.
 *
 * @param buf buffer that will be cutted.
 * @param n number of character that cut from buf.
 * @return new buf that cutted
 */
t_str_buf	*str_cut(t_str_buf *buf, size_t n, t_cut_dir dir)
{
	t_str_buf	*new_str;

	new_str = NULL;
	if (buf->length > n)
	{
		new_str = str_append_raw(NULL, buf->str + (n * dir), buf->length - n);
	}
	str_free(buf);
	return (new_str);
}
