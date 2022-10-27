/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:48:19 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 18:43:25 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENGINE_H
# define T_ENGINE_H
# include "t_world.h"
# include "t_mlx.h"

typedef struct s_render
{
	t_world	*world;
	t_mlx	*mlx;
}				t_render;

#endif

