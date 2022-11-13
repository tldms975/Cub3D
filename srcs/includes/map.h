/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:10:46 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 11:50:24 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cub3d.h"

t_result	map__read(t_info *info);
t_result	map__validate(t_info *info);

// create submaps for validation
void		map__openpath_create(t_info *info, t_path *open);
void		map__visited_create(t_info *info);
void		map__redzone_create(t_info *info);

// find player position & check duplicate start position
t_result	map__start_point__find(t_info *info);

// check map is surrounded by wall based on dijkstra algorithm
t_result	map__dij__path__release(t_info *info, t_path *open);
t_result	map__dij__path__select(t_path *open, t_coor *curr);
size_t		map__dij__path__add(t_path *open, t_coor *new_coor, size_t new_size);
void		map__dij__path__remove(t_path *open, t_coor curr);
void		map__dij__mark_visited(t_info *info, t_coor visited[4], size_t size);

// utils
char		map__check_char(char target);
void		map__coor__add(t_coor *result, size_t y, size_t x, int c);

void		print_raw(t_info *info);
void		print_redzone(t_info *info);
void		print_visited(t_info *info);

#endif // !MAP_H
