/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/25 04:32:39 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H
#include "string_buffer.h"
# include "t_mlx.h"
# include "t_vector.h"
# ifndef WIN_W
#  define WIN_W 1680
# endif
# ifndef WIN_H
#  define WIN_H 1050
# endif
# define TEX_H 64
# define TEX_W 64
# define MINI_W 180
# define MINI_H 180
# define T 12//w:120 T:8, w:240 T:16, w:180 T:12
# define DARKER 8355711
# define BASIC_CONFIG 6

typedef enum e_card
{
	NO = 0,
	SO,
	WE,
	EA,
	DOOR
}			t_card;

typedef struct s_rgb
{
	int	ceiling;
	int	floor;
}				t_rgb;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	char	cardinal;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_texture
{
	double	wall_x;
	t_card	type;
	double	step;
	double	pos;
}				t_texture;

typedef struct s_minimap_color
{
	int		bg;
	int		fg;
	int		wl;
}				t_minimap_color;
typedef struct s_draw
{
	int		line_h;
	int		start;
	int		end;
	t_ivec	tex;
}				t_draw;

typedef struct s_raycast
{
	t_vec		ray;
	t_ivec		block;
	t_ivec		step;
	t_vec		side;
	t_vec		delta;
	int			is_side;
	double		cam_y;
	double		d;
}				t_raycast;

typedef struct s_sprite
{
  int  id;
  t_vec pos;
} t_sprite;

typedef struct s_world
{
	t_mlx		*tmlx;
	int			**minimap_buf;
	size_t		minimap_w;
	size_t		minimap_h;
	char		**map;
	int			**screen_buf;
	size_t		screen_w;
	size_t		screen_h;
	int			*texture[5];
	char		*tex_path[5];
	t_rgb		rgb;
	t_player	player;
	t_raycast	rc;
	int			re;
	t_ivec		mouse;
	bool		mouse_on;
    size_t		spr_cnt;
    size_t		spr_capacity;
    t_sprite	*spr;
}				t_world;
#endif
