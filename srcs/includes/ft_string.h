/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:01:33 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 16:06:24 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING
# define FT_STRING

#include <stddef.h>
typedef struct s_string
{
	char	*content;
	size_t	len;
	size_t	size;
}	t_string;
	

#endif // !FT_STRING
