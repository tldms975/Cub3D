/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:10:46 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 01:11:32 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cub3d.h"

void		*realloc_map_raw_data(t_info *info);
t_result	scan_map(t_info *info);
t_result	read_map(t_info *info);

#endif // !MAP_H
