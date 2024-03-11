/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:09:54 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/11 20:41:28 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	initialize(&i, &j);
	if (!s1)
	{
		s1 = malloc (1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}
/*
int main()
{
	char *s1 = "Hello ";
	char *s2 = "World";

	printf("%s", ft_strjoin(s1, s2));
}
*/