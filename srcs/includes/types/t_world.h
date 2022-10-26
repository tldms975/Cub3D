/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:38:59 by sielee            #+#    #+#             */
/*   Updated: 2022/10/26 16:44:31 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H

typedef struct	s_ceiling
{

}				t_ceiling;

typedef struct	s_wall
{

}				t_wall;

typedef struct	s_floor
{
	
}				t_floor;

typedef struct	s_world
{
	char		**map;
	t_ceiling	*ceiling;
	t_wall		*wall;
	t_floor		*floor;
}				t_world;

#endif