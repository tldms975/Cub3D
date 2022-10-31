/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fcntl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:00:35 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/01 01:01:04 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"
#include "fcntl.h"
#include "stdio.h"

int str_safe_open(t_str_buf *path, int oflag)
{
	int fd;

	fd = open(str_dispose(path), oflag);
	if (fd == -1)
	{
		perror("Error: fail to open with given path: \n");
		exit(2);
	}
	return (fd);
}
