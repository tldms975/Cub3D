/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:10:46 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/12 02:45:22 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cub3d.h"

void		*realloc_map_raw_data(t_info *info);
t_result	map__scan(t_info *info);
t_result	map__read(t_info *info);

#endif // !MAP_H
