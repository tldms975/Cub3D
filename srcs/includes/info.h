/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:33:21 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/05 16:33:11 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

#include "cub3d.h"

int			init_texture_and_color(t_info *info, t_str_buf *line);
bool		read_color_and_texture(t_info *info);
t_result	read_info(t_info *info);
bool		parse_dot_cub(t_info *info, char* argv[]);
t_str_buf	*validate_path(char *argv[]);
void		add_start_point(t_info *info, size_t x, size_t y);
bool		is_start_point(t_info *info, size_t x, size_t y);
size_t		validate_char(t_info *info, size_t x, size_t y);
t_result	parse_curr_char(t_info *info, size_t x, size_t y);
t_result	gether_start_point(t_info *info);

#endif // !INFO_H
