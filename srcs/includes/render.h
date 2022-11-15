/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/15 18:38:23 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "t_world.h"
#include "t_mlx.h"
#include "t_motion.h"
#include "../libft/libft.h"
# include <stdlib.h>


void	ft_init_buf(int (*buf)[WIN_H][WIN_W]);
int		ft_init(t_mlx *tmlx, t_world *world);

int		ft_next_frame(t_world *world);

void	ft_move_player(int keycode, t_player *p);
void	ft_move_sight(int keycode, t_player *p);
int		ft_event_red_cross(int keycode);
int		ft_key_press(t_keycode keycode, t_world *world);


#endif