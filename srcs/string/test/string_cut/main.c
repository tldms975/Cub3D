/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/11/23 09:44:17 by hdoo             ###   ########.fr       */
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
	size_t size;
	int dir;
} t_tester_form;

int	main(int argc, char **argv)
{
	t_tester_form buff;
	t_str_buf *new;
	// char *new_char;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\t] %lu %d", buff.s, &buff.size, &buff.dir) != 3)
			break ;
		new = str_cut(str_append(NULL, buff.s), buff.size, buff.dir);
		if (new == NULL)
		{
			printf("NULL\n");
		}
		else if (new->str == NULL)
			puts("invalid");
		else
		{
			str_append(new, "\n");
			write(1, new->str, new->length);
			// new_char = str_dispose(new);
			// printf("%s\n", new_char);
		}
		free_safe(str_dispose(new));
		// free_safe(new_char);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
