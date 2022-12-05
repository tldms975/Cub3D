/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:31:51 by sielee            #+#    #+#             */
/*   Updated: 2022/12/05 15:40:12 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECTOR_H
# define T_VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_ivec
{
	int	x;
	int	y;
}				t_ivec;

#endif // T_VECTOR_H
