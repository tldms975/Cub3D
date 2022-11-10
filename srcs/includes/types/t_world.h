/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/11/10 15:06:33 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H

typedef	enum
{
	NO = 0,
	SO,
	WE,
	EA
} t_dir;

typedef struct	s_ceiling
{
	int	rgb;
}				t_ceiling;

typedef struct	s_wall
{
	int	rgb;
}				t_wall;

typedef struct	s_floor
{
	int	rgb;
}				t_floor;

typedef struct	s_sprite
{
	int	rgb;
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
	char	cardinal;
}				t_player;

typedef struct	s_world
{
	t_ceiling	ceiling;
	t_wall		wall;
	t_floor		floor;
	char		*txr[4];
	t_player	*player;
}				t_world;

#endif

