/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:34 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/11 20:47:58 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_lock;

void	end_program(int signal)
{
	if (signal == SIGUSR2)
	{
		write(1, "Message sent and signal received.\n", 34);
		exit(1);
	}
	else
		g_lock = 0;
}

void	send_char(int pid, unsigned char c)
{
	int	bits;

	g_lock = 1;
	bits = 7;
	while (bits >= 0)
	{
		if (((c >> bits) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(256);
		bits--;
	}
	while (g_lock)
		pause();
}

void	send_len(int pid, int len)
{
	int		i;
	char	*length;

	i = 0;
	length = ft_itoa(len);
	while (length[i])
		send_char(pid, length[i++]);
	send_char(pid, '\0');
	free(length);
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client PID STRING", 1);
		exit(1);
	}
	pid = atoi(argv[1]);
	signal(SIGUSR1, end_program);
	signal(SIGUSR2, end_program);
	// send_len(pid, ft_strlen(argv[2]));
	send_str(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
