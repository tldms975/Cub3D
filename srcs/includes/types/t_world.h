/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/10/31 17:07:53 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H

typedef	enum
{
	NO,
	SO,
	WE,
	EA
} t_dir;



typedef struct	s_ceiling
{
	int	color;
}				t_ceiling;

typedef struct	s_wall
{
	int	color;
}				t_wall;

typedef struct	s_floor
{
	int	color;
}				t_floor;

typedef struct	s_sprite
{
	int	color;
}				t_sprite;

typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_player
{
	double	speed;
	t_vec	pos;
	double	sight;
}				t_player;

typedef struct	s_world
{
	char		**map;
	t_ceiling	ceiling;
	t_wall		wall;
	t_floor		floor;
	int			txr[4];
	t_player	*player;
}				t_world;

#endif

