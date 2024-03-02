/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:46 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 16:58:01 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	const char	*char_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	char_dest = dst;
	char_src = src;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dst);
}
