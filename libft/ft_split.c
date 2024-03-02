/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:22 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 16:06:50 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "ft_strlen.c"
// #include "ft_strlcpy.c"

static int	count_words(char const *str, char const c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while ((str[i] != 0) && (str[i] == c))
			i++;
		if (str[i])
			words++;
		while ((str[i] != 0) && (str[i] != c))
			i++;
	}
	return (words);
}

static int	word_len(char const *str, char const c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	initial_config(int *i, int *j, int size, char ***tab)
{
	*i = 0;
	*j = 0;
	*tab = (char **) malloc(size * sizeof(char *));
	if (*tab == NULL)
		return (0);
	else
		return (1);
}

static int	null_handler(char **tab, int *i)
{
	int	index;

	index = *i;
	if (tab[index] == NULL)
	{
		while (index--)
			free(tab[index]);
		free(tab);
		return (0);
	}
	*i = index;
	return (1);
}

char	**ft_split(char const *s, char const c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s || (initial_config(&i, &j, (count_words(s, c) + 1), &tab) == 0))
		return (NULL);
	while (i < count_words(s, c))
	{
		if (s[j] != c)
		{
			tab[i] = (char *) malloc((word_len((s + j), c) + 1) * sizeof(char));
			if (null_handler(tab, &i) == 0 || tab[i] == NULL)
				return (NULL);
			ft_strlcpy(tab[i], (char *) s + j, word_len((s + j), c) + 1);
			j += word_len((s + j), c);
			i++;
		}
		else
		{
			j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

/*
int	main(int argc, char *argv[])
{
	(void) argc;
	int i = 0;
	char c = argv[2][0];
	char **tab;

	tab = ft_split(argv[1], c);
	while (tab[i])
	{
		printf("%s\n", tab[i++]);
	}
}

int	main(void) {
	char *str = "Hello World of Fame!";
	char c = ' ';
	char **tab = ft_split(str, c);
	int	i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i++]);
	}
}
*/
