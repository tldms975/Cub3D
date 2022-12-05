/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:16:17 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 14:18:48 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H
# include "cub3d.h"
# include "types/t_keycode.h"

int			t_key_press(t_keycode keycode, t_info *info);
int			t_key_release(t_keycode keycode, t_info *info);
int			t_event_red_cross(int keycode);
size_t		find_key(const int keycode);
void		action_internal(const t_keycode key, t_world *world);
void		ft_door(t_world *world);
void		ft_event_close(t_world *world);
void		reset_mouse_pos(t_info *info);
void		ft_toggle_mouse(t_world *world);
void		action_by_each_keys(t_info *info);
void		ft_toggle_minimap(t_world *world);
t_result	action(t_info *info);
t_keycode	which_is_functinal(t_keycode key1, t_keycode key2, int keycode);

#endif // !KEY_H
