/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/16 01:20:33 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdlib.h>
# include "t_world.h"
# include "t_mlx.h"
# include "t_keycode.h"
# include "../libft/libft.h"

void	ft_init_buf(int (*buf)[WIN_H][WIN_W]);
int		ft_init_render(t_mlx *tmlx, t_world *world);

int		ft_next_frame(t_world *world);

void	ft_move_player(int keycode, t_player *p);
void	ft_move_sight(int keycode, t_player *p);
int		ft_event_red_cross(int keycode);
int		ft_key_press(t_keycode keycode, t_world *world);

int		*ft_load_image(char *path, t_mlx *tmlx);
void	tmp_load_image(t_mlx *tmlx, int *texture, char *path, t_image *timg);
void	tmp_load_texture(t_world *world);
int		**ft_init_texture(void);

#endif