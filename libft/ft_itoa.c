/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:04:32 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 21:42:53 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	int	counter;

	counter = 1;
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static unsigned int	ft_set_sign(int n)
{
	unsigned int	num;

	num = (n * -1);
	if (n >= 0)
		num = n;
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				size;
	int				i;
	char			*result;

	if (n == 0)
		return (ft_strdup("0"));
	num = ft_set_sign(n);
	size = count_digits(num);
	i = size - (n >= 0);
	result = (char *) malloc((size + (n < 0) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	while (i >= (n < 0))
	{
		result[i--] = ((num % 10) + 48);
		num /= 10;
	}
	if (n > 0)
		result[size] = 0;
	else
		result[(size + 1)] = 0;
	return (result);
}
/*
int main()
{
    //printf("%d", count_digits(0));
    printf("%s", ft_itoa(0));
}*/