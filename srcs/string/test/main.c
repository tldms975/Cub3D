/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/10/27 22:14:36 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "string_buffer.h"

typedef struct s_tester_form
{
	char s[1024];
	size_t size;
	int dir;
} t_tester_form;

int	main(int argc, char **argv)
{
	t_tester_form buff;
	t_str_buf *new;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\n]", buff.s) != 1 || \
				scanf("%lu\n", &buff.size) != 1 || \
				scanf("%d\n", &buff.dir) != 1)
			break ;
		new = str_cut(str_append(NULL, buff.s), buff.size, buff.dir);
		if (new->str == NULL)
			puts("invalid");
		else
			write(1, new->str, new->length);
		str_free(new);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
