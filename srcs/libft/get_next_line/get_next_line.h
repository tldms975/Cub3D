/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:21:50 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 15:43:47 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdbool.h>

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif // !FT_NULL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // !BUFFER_SIZE

# ifndef SIZE_T
#  define SIZE_T

typedef unsigned int	t_size;
# endif  /* SIZE_T */

# ifndef TRUE
#  define TRUE 1
# endif // !TRUE

# ifndef FALSE
#  define FALSE 0
# endif // !FALSE

typedef struct s_segment
{
	char				*segment;
	struct s_segment	*next;
}	t_segment;

typedef struct s_file
{
	int				fd;
	struct s_file	*next;
	struct s_file	*prev;
	bool			is_eol : 1;
	bool			is_eof : 1;
	t_size			rd_size;
	long			line_end;
	long			line_stt;
	t_segment		*list;
	t_segment		*last_list;
}	t_file;

char	*get_next_line(int fd);
t_file	*init_fd(int fd);
int		addback_seg(t_file *curr);
void	save_remain(t_file *curr);
int		link_lines(t_file **curr, char **result);
void	free_used_segment(t_file *curr);
void	free_ended_fd_data(t_file **fd_data, t_file *curr);

#endif // !GET_NEXT_LINE_BONUS_H
