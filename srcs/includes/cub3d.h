/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:23 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/27 18:56:10 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "string_buffer.h"
# include "types/t_engine.h"
# include "types/t_mlx.h"
# include "types/t_world.h"
# include "types/t_engine.h"

typedef struct s_core
{
	t_mlx		mlx;
	t_world		world;

}	t_core;

// every information of config
typedef struct s_info
{
	t_str_buf	*path;
	char		**map;
	int			fd;
	t_core		core;
}	t_info;

#endif

