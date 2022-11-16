/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:45:02 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/16 19:16:52 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"

void	skip_delimiter(size_t *i, char *str, char delimiter)
{
	while (str[*i] == delimiter)
		(*i)++;
}

t_str_buf	*str_split(t_str_buf *target, const char del, const int field)
{
	t_str_buf	*result;
	size_t		i;
	int			field_i;

	result = NULL;
	i = 0;
	field_i = 1;
	while (i < target->length)
	{
		if (target->str[i] == del)
		{
			skip_delimiter(&i, target->str, del);
			if (field_i == field)
				return (result = str_cut(target, i, FWD));
			field_i++;
			if (field_i == field)
				return (result = str_cut(target, target->length - i, BWD));
		}
		i++;
	}
	return (result);
}
