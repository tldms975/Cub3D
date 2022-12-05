/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <hdoo@student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:23:47 by yui               #+#    #+#             */
/*   Updated: 2022/12/05 21:16:56 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "types/t_world.h"

void	ft_draw_sprite(t_sprite *s, t_world *world);
void	ft_init_sprite(t_sprite *s, t_player *p);
void	ft_swap(t_spr_arr *a, t_spr_arr *b);
int		*ft_get_sprite_order(t_sprite *s, int n);
void	ft_show_sprite(t_world *world);
void	ft_init_sprite(t_sprite *s, t_player *p);
int		init_order(int **ret, int n);
void	init_spr_arr(t_sprite *s, t_spr_arr **arr, int n);
void	put_sprite(t_sprite *s, t_world *world, t_ivec *line, t_ivec *tex);
int		calculate_tex_x(t_sprite *s, t_world *world, t_ivec line);
void	ft_swap(t_spr_arr *a, t_spr_arr *b);
void	swap_spr_arr(t_spr_arr *arr, int n);

#endif // !SPRITE_H
