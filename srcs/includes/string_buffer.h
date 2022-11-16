/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:37:17 by jkong             #+#    #+#             */
/*   Updated: 2022/11/16 16:51:44 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUFFER_H
# define STRING_BUFFER_H

# include "libft.h"
# include <sys/fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef INITIAL_CAPACITY
#  define INITIAL_CAPACITY 0x20
# endif

# ifndef GROW_THRESHOLD
#  define GROW_THRESHOLD 0x400
# endif

# ifndef MATCH
#  define MATCH 0x00
#endif // !MATCH

typedef struct s_str_buf
{
	size_t	length;
	size_t	capacity;
	char	*str;
}	t_str_buf;

typedef enum e_cut_dir
{
	FWD = 1,
	BWD = 0
} t_cut_dir;

t_str_buf	*str_append_raw(t_str_buf *buf, const char *s, size_t n);
t_str_buf	*str_append(t_str_buf *buf, const char *s);
char		*str_dispose(t_str_buf *buf);
t_str_buf	*str_append_number(t_str_buf *buf, int n);
t_str_buf	*str_append_character(t_str_buf *buf, char c);
t_str_buf	*str_append_optional(t_str_buf *buf, char *s, char *def);
t_str_buf	*str_append_format(t_str_buf *buf, const char *format, ...);
t_str_buf	*str_append_format_v(t_str_buf *buf, const char *format,
				va_list *ap);
t_str_buf	*str_cut(t_str_buf *buf, size_t n, t_cut_dir dir);
int			str_compare(const t_str_buf *s1, const char *s2);
int			str_ncompare(const t_str_buf *s1, const char *s2, size_t n);
void		str_free(t_str_buf *buf);
int			str_safe_open(t_str_buf *path, int oflag);
t_str_buf	*str_split(t_str_buf *target, const char del, const int field);

#endif
