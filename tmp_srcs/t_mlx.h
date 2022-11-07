/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:40:56 by sielee            #+#    #+#             */
/*   Updated: 2022/11/01 20:20:07 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H
# include "../libmlx/mlx.h"


typedef struct s_image
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_image;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_image	timg;
}				t_mlx;

#endif

