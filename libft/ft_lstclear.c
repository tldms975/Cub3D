/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:24:40 by hdoo              #+#    #+#             */
/*   Updated: 2021/12/07 09:05:30 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_next;
	t_list	*temp_current;

	temp_current = *lst;
	while (temp_current != NULL)
	{
		temp_next = temp_current->next;
		ft_lstdelone(temp_current, del);
		temp_current = temp_next;
	}
	*lst = NULL;
}
