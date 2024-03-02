/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:04 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 17:00:57 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*next;

	if (!del || !lst || !*lst)
		return ;
	actual = *lst;
	while (actual != NULL)
	{
		next = actual->next;
		del(actual->content);
		free(actual);
		actual = next;
	}
	*lst = NULL;
}
