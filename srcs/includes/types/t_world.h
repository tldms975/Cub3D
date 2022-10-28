/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/10/28 15:30:42 by hdoo             ###   ########.fr       */
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

typedef struct s_rgb
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

typedef struct	s_sprite
{
	t_rgb	rgb;
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
	char		*txr[4];
	t_player	*player;
}				t_world;

#endif

