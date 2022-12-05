/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:11:01 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 16:12:11 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

#include "cub3d.h"

void	ft_player_on_minimap(t_info *info, t_player *p);
void	ft_fill_miniimap_block(t_info *info, int y, int x, int color);
void	ft_minimap_on_screen(t_info *info, t_mlx *tmlx);
void	ft_set_minimap(t_info *info);
void	set_minimap_color(t_minimap_color *color);
void	put_color(t_info *info, size_t x, size_t y, t_minimap_color color);

#endif // !MINIMAP_H
