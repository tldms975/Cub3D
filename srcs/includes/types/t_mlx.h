/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:40:56 by sielee            #+#    #+#             */
/*   Updated: 2022/12/06 01:44:17 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H
# define FRAME_LIMIT 1024

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
	t_image	timg_wall_tex[5];
	t_image	timg_spr_tex[FRAME_LIMIT];
	t_image	timg_mini;
}				t_mlx;

#endif
