/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:34 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/12 01:21:14 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_lock = 1;

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2)
		g_lock = 0;
	else
	{
		write(1, "Message sent and signal received.\n", 34);
		exit(1);
	}
}

void	send_bit(int pid, char c, int *i)
{
	g_lock = 1;
	if ((c >> *i) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	(*i)--;
	while (g_lock == 1)
		usleep(100);
}

void	send_null(int pid)
{
	int	i;

	i = 8;
	while (i)
	{
		g_lock = 1;
		kill(pid, SIGUSR2);
		i--;
		while (g_lock == 1)
			usleep(100);
	}
}

void	send_str(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
			send_bit(pid, c, &i);
	}
	if (*str == '\0')
	{
		i = 8;
		send_null(pid);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_putstr_fd("Usage: ./client PID STRING", 1);
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(pid, argv[2]);
	return (0);
}
