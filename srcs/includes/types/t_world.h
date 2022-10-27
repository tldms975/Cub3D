/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/10/27 16:15:43 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_ceiling
{
	t_rgb	rgb;
}				t_ceiling;

typedef struct	s_wall
{
	t_rgb	rgb;
}				t_wall;

typedef struct	s_floor
{
	t_rgb	rgb;
}				t_floor;

typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_camera
{
	t_vec				pos;
	t_vec				dir;
	t_vec				plane;
}				t_camera;

typedef	enum{
	NO,
	SO,
	WE,
	EA
};

typedef struct	s_world
{
	char		**map;
	t_ceiling	*ceiling;
	t_wall		*wall;
	t_floor		*floor;
	t_camera	*camera;
	int			fd_texture[4];
}				t_world;

#endif