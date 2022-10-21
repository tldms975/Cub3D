/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:50:16 by hdoo              #+#    #+#             */
/*   Updated: 2022/05/04 19:28:03 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(long long int target)
{
	long long int	sqrt;
	long long int	stt;
	long long int	end;
	int				i;

	sqrt = target / 2;
	stt = 0;
	end = target;
	i = 0;
	while (i < 100)
	{
		if (sqrt * sqrt > target)
		{
			end = sqrt;
			sqrt = (sqrt + stt) / 2;
		}
		else
		{
			stt = sqrt;
			sqrt = (sqrt + end) / 2;
		}
		i++;
	}
	return (sqrt);
}
