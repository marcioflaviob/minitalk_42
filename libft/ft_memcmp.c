/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:40 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 14:23:15 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = s1;
	c2 = s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
		i++;
	}
	return (0);
}
