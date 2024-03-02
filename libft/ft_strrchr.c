/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:10:25 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/16 20:33:27 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;
	int				last;

	ch = c;
	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == ch)
			last = i;
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	if (last == -1)
		return ((char *) 0);
	else
		return ((char *)(s + last));
}
