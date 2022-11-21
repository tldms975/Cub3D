/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:34 by sielee            #+#    #+#             */
/*   Updated: 2022/11/21 20:27:01 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdlib.h>
# include "types/t_world.h"
# include "types/t_mlx.h"
# include "types/t_keycode.h"
# include "mlx.h"
# include "cub3d.h"
# include "libft.h"

void	ft_run_cub3d(t_info *info);

void	ft_init_screen_buf(t_info *info);
int		ft_init_render(t_info *info);

int		ft_next_frame(void *w);

int		ft_key_press(t_keycode keycode, t_world *world);
int		ft_event_red_cross(int keycode);
void	ft_move_player(int keycode, t_world *w);
void	ft_move_sight(int keycode, t_player *p);

void	ft_load_texture(t_info *info);

void	ft_check_hit(t_world *world, t_player *p, t_raycast *rc);
void	ft_step_dir(t_player *p, t_raycast *rc);
void	ft_init_rc(t_world *world, t_raycast *rc, int x);
void	ft_background(t_world *world);

void	ft_set_world(t_info *i);
void	ft_set_minimap(t_info *info);

void	ft_world_on_screen(t_info *info, t_mlx *tmlx);
void	ft_minimap_on_screen(t_info *info, t_mlx *tmlx);

#endif
