/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:23 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/22 06:30:16 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "string_buffer.h"
# include "types/t_mlx.h"
# include "types/t_world.h"

# define PUPLE "\x1b[38;2;172;146;235m"
# define RED "\x1b[38;2;236;86;101m"
# define BLUE "\x1b[38;2;114;191;228m"
# define ORANGE "\x1b[38;2;248;145;76m"
# define YELLOW "\x1b[38;2;254;206;83m"
# define GREEN "\x1b[38;2;172;210;118m"
# define NOCOLOR "\x1b[0;0m"
# define VALID_C_NUM 9

typedef enum e_state
{
	WALL = 0,
	INSIDE = 1,
	OUTSIDE = 2,
}	t_state;

typedef enum e_result
{
	FAILURE = 0,
	SUCCESS = 1,
	ERROR = 2
}	t_result;

typedef struct s_core
{
	t_mlx		mlx;
	t_world		world;
}	t_core;

typedef struct s_coor
{
	size_t	x;
	size_t	y;
	char	c;
}	t_coor;

typedef struct s_path
{
	t_coor	*path;
	size_t	count;
	size_t	capacity;
}	t_path;

typedef struct s_map
{
	t_str_buf		**raw;
	bool			**visited;
	bool			**redzone;
	t_path			opened;
	size_t			width;
	size_t			capacity;
	size_t			height;
}	t_map;

// every information of config
typedef struct s_info
{
	t_str_buf		*cub_path;
	t_map			map;
	int				fd;
	t_core			core;
	unsigned int	keycode;
}	t_info;

#endif
