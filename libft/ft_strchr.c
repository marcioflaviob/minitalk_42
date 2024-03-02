/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:35 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 14:38:04 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	ch = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == 0)
		return ((char *)(s + i));
	return (0);
}
