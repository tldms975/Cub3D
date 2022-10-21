/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:36:57 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/06 15:53:59 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	write_last_digit(unsigned int unsigned_number, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unsigned_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		unsigned_n = n * -1;
	}
	else
		unsigned_n = (unsigned)n;
	if (unsigned_n != 0 && unsigned_n / 10 == 0)
	{
		write_last_digit(unsigned_n, fd);
		return ;
	}
	else if (unsigned_n > 0)
	{
		ft_putnbr_fd((int)(unsigned_n / 10), fd);
		write_last_digit(unsigned_n, fd);
	}
	else if (n == 0)
		write(fd, "0", 1);
}

static void	write_last_digit(unsigned int unsigned_number, int fd)
{
	unsigned_number %= 10;
	unsigned_number += '0';
	write(fd, &unsigned_number, 1);
}
