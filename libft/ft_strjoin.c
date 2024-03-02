/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:09:54 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 20:43:01 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size_s2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s2 = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + size_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char *s1 = "Hello ";
	char *s2 = "World";

	printf("%s", ft_strjoin(s1, s2));
}
*/