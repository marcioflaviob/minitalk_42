/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:03:57 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/17 18:53:40 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	totalsize;
	void			*arr;

	if (count > 0 && 2147483647 / count < size)
		return (NULL);
	if (size > 0 && 2147483647 / size < count)
		return (NULL);
	totalsize = count * size;
	arr = malloc(totalsize);
	if (arr == NULL)
		return (NULL);
	else
		ft_bzero(arr, totalsize);
	return (arr);
}

/*
void	*ft_calloc(size_t count, size_t size)
{
	size_t		totalsize;
	void		*arr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	totalsize = count * size;
	arr = malloc(totalsize);
	if (arr == NULL)
		return (NULL);
	else
		ft_bzero(arr, totalsize);
	return (arr);
}
*/
/*
static char *null_handler()
{
	char    *str;

	str = malloc(1);
	str[0] = '\0';
	return (str);
}

// OLD CALLOC (PASSES ONE TESTER)
void    *ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	void	*arr;

	if (count == 0 || size == 0)
		return (null_handler());
	if (count >= SIZE_MAX || size >= SIZE_MAX || SIZE_MAX / count < size)
		return (NULL);
	totalsize = count * size;
	arr = (void *) malloc(totalsize);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	ft_bzero(arr, count);
	return (arr);
}
int main()
{
	printf("%s", ((char *) ft_calloc(INT_MIN, INT_MIN)));
	return (0);
}
*/