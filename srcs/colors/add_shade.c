/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:22:56 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 01:26:11 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add_shade(double distance, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color & 0x00FF0000) >> 16;
	g = (color & 0x0000FF00) >> 8;
	b = (color & 0x000000FF);
	r = r / distance;
	g = g / distance;
	b = b / distance;
	return (r << 16 | g << 8 | b);
}
