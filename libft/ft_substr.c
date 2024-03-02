/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:10:34 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 18:52:22 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*null_handler(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static int	initial_config(size_t *i, size_t *s_len, char const **s)
{
	*i = 0;
	if (*s == NULL)
		return (0);
	*s_len = ft_strlen(*s);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	real_len;
	char	*str;

	if (initial_config(&i, &s_len, &s) == 0)
		return (NULL);
	if (start > (s_len - 1))
		return (null_handler());
	real_len = len;
	if (len > (s_len - start))
		real_len = (s_len - start);
	str = (char *) malloc((real_len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (null_handler());
	}
	while (i < real_len)
	{
		str[i] = (s + start)[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
int main()
{
    char *str = "Hello Wonderful World!";
    printf("%s", ft_substr(str, 6, 9));
    return (0);
}
*/
