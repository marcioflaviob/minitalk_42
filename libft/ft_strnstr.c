/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:10:20 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 19:09:51 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	initial_config(size_t *i, size_t *j, size_t *len, const char **h)
{
	*i = 0;
	*j = 0;
	if (*h == NULL && *len == 0)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		temp_index;
	size_t		j;

	if (initial_config(&i, &j, &len, &haystack) == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		temp_index = i;
		while (needle[j] && (needle[j] == haystack[i + j]) && temp_index < len)
		{
			temp_index++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		else
		{
			j = 0;
			i++;
		}
	}
	if (needle[j] == '\0')
		return ((char *)(haystack + i));
	return (0);
}
