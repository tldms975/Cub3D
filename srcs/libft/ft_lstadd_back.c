/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:29:41 by hdoo              #+#    #+#             */
/*   Updated: 2022/01/20 18:51:24 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
}
