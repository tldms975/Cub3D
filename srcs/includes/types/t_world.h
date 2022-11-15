/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/15 18:36:26 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H
#define WIN_W 640//1200
#define WIN_H 480//700
#define DARKER 8355711
typedef	enum
{
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C
} t_dir;

typedef struct	s_rgb
{
	int	ceiling;
	int	floor;
}				t_rgb;

typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_ivec
{
	int	x;
	int	y;
}				t_ivec;

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


typedef struct	s_raycast
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

typedef struct	s_world
{
	t_mlx		*tmlx;
	int			**map;
	int			buf[WIN_H][WIN_W];
	int			**texture;
	char		**tex_path;
	t_rgb		rgb;
	t_player	player;
	t_raycast	rc;
	int			re;
}				t_world;

#endif

