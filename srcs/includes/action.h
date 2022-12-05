/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:42:31 by hdoo              #+#    #+#             */
/*   Updated: 2022/12/05 15:38:11 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H
# include "render.h"

void	ft_move_right(t_world *world);
void	ft_move_left(t_world *world);
void	ft_move_backward(t_world *world);
void	ft_move_foreward(t_world *world);

#endif /* !ACTION_H */
