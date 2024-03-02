/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:36 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 14:21:57 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*us;
	unsigned char		uc;

	i = 0;
	us = s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (us[i] == uc)
		{
			return ((void *)(us + i));
		}
		i++;
	}
	return (NULL);
}
