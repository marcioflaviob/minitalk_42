/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/12 01:20:57 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_bit(int signum, char *c)
{
	*c <<= 1;
	if (signum == SIGUSR1)
		*c |= 1;
}

void	free_and_print(char **str, int *i, siginfo_t *info)
{
	ft_putstr_fd(*str, 1);
	free(*str);
	*str = NULL;
	*i = 0;
	kill(info->si_pid, SIGUSR1);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static char	*str;
	static int	i;

	(void)context;
	set_bit(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (c == '\0')
			free_and_print(&str, &i, info);
		else
			str = ft_strjoin(str, &c);
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
