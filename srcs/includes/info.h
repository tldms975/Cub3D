/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:33:21 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/10 15:14:23 by hdoo             ###   ########.fr       */
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

#endif // !INFO_H
