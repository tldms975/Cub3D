/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:24:42 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/09 12:48:30 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	put_splited_strings(char const *string_origin, char delimiter, \
								char **splited_strs, int word_count);
static int	count_word(char const *string_origin, char delimiter);
static int	get_word_lenth(char const *string_origin, char delimiter);
static void	*free_strings_return_null(char **splited_strs, int word_count);

char	**ft_split(char const *s, char c)
{
	char	**splited_strs;
	char	*string_origin;
	char	delimiter;
	int		word_count;

	if (s == NULL)
		return (NULL);
	string_origin = (char *)s;
	delimiter = c;
	word_count = count_word(string_origin, delimiter);
	splited_strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (splited_strs == NULL)
		return (free_strings_return_null(splited_strs, 0));
	put_splited_strings(string_origin, delimiter, splited_strs, word_count);
	splited_strs[word_count] = NULL;
	return (splited_strs);
}

static void	put_splited_strings(char const *string_origin, char delimiter, \
								char **splited_strs, int word_count)
{
	int	word_lenth;
	int	index;

	index = 0;
	while (*string_origin != '\0')
	{
		while (*string_origin == delimiter && *string_origin != '\0')
			string_origin++;
		word_lenth = get_word_lenth(string_origin, delimiter);
		if (word_lenth > 0)
			splited_strs[index] = ft_substr(string_origin, 0, word_lenth);
		else
			return ;
		if (splited_strs[index] == NULL)
			(free_strings_return_null(splited_strs, word_count));
		index++;
		string_origin += word_lenth;
	}
}

static int	count_word(char const *string_origin, char delimiter)
{
	int		word_lenth;
	int		word_count;

	word_lenth = 0;
	word_count = 0;
	while (*string_origin != '\0')
	{
		while (*string_origin == delimiter && *string_origin != '\0')
			string_origin++;
		word_lenth = get_word_lenth(string_origin, delimiter);
		if (word_lenth > 0)
			word_count++;
		string_origin += word_lenth;
	}
	return (word_count);
}

static int	get_word_lenth(char const *string_origin, char delimiter)
{
	int	word_lenth;

	word_lenth = 0;
	while (string_origin[word_lenth] != delimiter && \
		string_origin[word_lenth] != '\0')
	{
		word_lenth++;
	}
	return (word_lenth);
}

static void	*free_strings_return_null(char **splited_strs, int word_count)
{
	int	i;

	i = 0;
	while (i < word_count)
	{
		free(splited_strs[i]);
		i++;
	}
	free(splited_strs);
	return (NULL);
}
