/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:09:58 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 16:49:31 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (dstsize <= dest_len)
		return (src_len + dstsize);
	while ((i < dstsize - dest_len - 1) && src[i] != '\0')
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}
