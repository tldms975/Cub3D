/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keycode.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:39:02 by sielee            #+#    #+#             */
/*   Updated: 2022/11/17 18:05:32 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEYCODE_H
# define T_KEYCODE_H

typedef enum e_keycode
{
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_DESTROY_NOTIFY = 17,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
	KEY_ARROW_L = 123,
	KEY_ARROW_R = 124
}		t_keycode;

#endif

