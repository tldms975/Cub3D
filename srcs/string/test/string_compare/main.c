/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/11/23 09:49:30 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "string_buffer.h"

typedef struct s_tester_form
{
	char s[1024];
	char compare_to[1024];
} t_tester_form;

int main(int argc, char** argv)
{
	t_tester_form buff;
	int result;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\t] %1000[^\n]", buff.s, buff.compare_to) != 2)
			break;
		result = str_compare(str_append(NULL, buff.s), buff.compare_to);
		if (result == 0)
		{
			puts("1");
		}
		else
		{
			puts("0");
		}
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
