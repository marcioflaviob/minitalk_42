/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:34 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/01 22:57:13 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

void	end_program(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message sent and signal received.\n", 34);
	exit(1);
}

void	char_to_bin(char *str, int pid)
{
	unsigned char	ch;
	int				i;
	int				bits;

	i = 0;
	while (str[i])
	{
		ch = str[i];
		bits = 7;
		while (bits >= 0)
		{
			if (((ch >> bits) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bits--;
		}
		i++;
	}
	bits = 7;
	while (bits >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		bits--;
	}
}

int main(int argc, char *argv[])
{
	(void)argc;
	int	pid;

	pid = atoi(argv[1]);
	signal(SIGUSR2, end_program);
	char_to_bin(argv[2], pid);
	return 0;
}
