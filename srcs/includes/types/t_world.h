/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/17 19:25:21 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H
# include "t_mlx.h"
# include "t_vector.h"
# define WIN_W 640
# define WIN_H 480
# define TEX_H 64
# define TEX_W 64
# define MAP_W 24//tmp
# define MAP_H 24//tmp
# define MINI_W 180
# define MINI_H 180
# define T 12//w:120 T:8, w:240 T:16, w:180 T:12
# define DARKER 8355711

typedef enum e_parsing_element
{
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C
}			t_parsing_element;

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
	int		type;
	double	step;
	double	pos;
}				t_texture;

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
	double		cam_x;
	double		d;
}				t_raycast;

typedef struct s_world
{
	t_mlx		*tmlx;
	t_image		minimap;
	int			minimap_buf[MINI_H][MINI_W];
	char		**map;
	int			screen_buf[WIN_H][WIN_W];
	int			texture[4];
	char		*tex_path[4];
	t_rgb		rgb;
	t_player	player;
	t_raycast	rc;
	int			re;
}				t_world;

#endif
