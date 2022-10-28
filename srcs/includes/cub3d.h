/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:23 by hdoo              #+#    #+#             */
/*   Updated: 2022/10/29 02:11:20 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "string_buffer.h"
# include "types/t_engine.h"
# include "types/t_mlx.h"
# include "types/t_world.h"
# include "types/t_engine.h"

typedef enum e_result {
	FAILURE = 0,
	SUCCESS = 1
}	t_result;

typedef struct s_core
{
	t_mlx		mlx;
	t_world		world;
}	t_core;

typedef struct s_map
{
	t_str_buf		**raw_data;
	size_t		width;
	size_t		capacity;
	size_t		height;
}	t_map;

// every information of config
typedef struct s_info
{
	t_str_buf	*path;
	t_map		map;
	int			fd;
	t_core		core;
}	t_info;

#endif
