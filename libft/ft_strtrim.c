/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:10:30 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 16:37:00 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_char_set(set, s1[i]))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_rev_count(const char *s1, const char *set, size_t a)
{
	while (a > 0)
	{
		a--;
		if (!ft_char_set(set, s1[a]))
			return (a + 1);
	}
	return (a + 1);
}

static void	ft_trim_len(char *dst, const char *s1, size_t i, size_t a)
{
	size_t	j;

	j = 0;
	while (i < a)
	{
		dst[j] = s1[i];
		j++;
		i++;
	}
	dst[j] = '\0';
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_trim;
	size_t	end_trim;
	char	*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end_trim = ft_strlen(s1);
	start_trim = ft_count(s1, set);
	if (start_trim != end_trim)
		end_trim = ft_rev_count(s1, set, end_trim);
	dst = (char *)malloc((end_trim - start_trim) + 1 * sizeof(char));
	if (dst != NULL)
		ft_trim_len(dst, s1, start_trim, end_trim);
	return (dst);
}
/*
int main()
{
char *str = "awdadsd";
printf("%s", ft_strtrim(str, "lllllllllllllllllll"));
}
*/