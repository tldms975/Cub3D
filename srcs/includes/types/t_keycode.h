/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keycode.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:39:02 by sielee            #+#    #+#             */
/*   Updated: 2022/12/03 19:09:22 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEYCODE_H
# define T_KEYCODE_H
#include "t_world.h"

typedef enum e_keycode
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_M = 46,
	KEY_O = 31,
	KEY_TAB = 48,
	KEY_ESC = 53,
	KEY_ARROW_L = 123,
	KEY_ARROW_R = 124,
	KEY_NONE = -1
}		t_keycode;

typedef enum e_event
{
	X_EVENT_ON_MOUSEMOVE = 6,
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_DESTROY_NOTIFY = 17,
}		t_event;

typedef void (*t_key_action)(t_world *world);

#endif

