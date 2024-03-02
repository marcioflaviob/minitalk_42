/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:40:36 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 13:54:41 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = sign * (1 - 2 * (str[i++] == '-'));
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

/*
int main(int argc, char *argv[])
{
    (void) argc;
    int a = ft_atoi(argv[1]);
    int b = atoi(argv[1]);
    printf("%d, %d", a, b);
    return 0;
}
*/