/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:04:36 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 14:13:50 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static t_list *ft_lstlast(t_list *lst)
{
    while (lst->next != NULL)
        lst->next;
    return lst;
}*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
