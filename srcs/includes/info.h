/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:33:21 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/04 16:37:08 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "cub3d.h"
# define CONFIG_NUM 4

t_result	init_config(t_info *info, char *line, size_t *limits);
bool		read_config(t_info *info);
t_result	read_info(t_info *info);
bool		parse_dot_cub(t_info *info, char *arg);
void		free_config(t_info *info);

#endif // !INFO_H
