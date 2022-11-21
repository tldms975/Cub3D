/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:40:56 by sielee            #+#    #+#             */
/*   Updated: 2022/11/21 19:53:32 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	timg_main;
	t_image	timg_texture[4];
	t_image	timg_mini;
}				t_mlx;

#endif
