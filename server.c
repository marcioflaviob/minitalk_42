/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/01 22:50:01 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bits;
	static int	ch = 0;

	(void) context;
	(void) info;
	if (sig == SIGUSR2)
		ch |= 1;
	bits++;
	if (bits == 8)
	{
		if (ch == '\0')
			kill(info->si_pid, SIGUSR2);
		ft_putchar_fd(ch, 1);
		bits = 0;
		ch = 0;
	}
	else
		ch <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = sig_handler;
	sigemptyset(&s_sigaction.sa_mask);
	sigaddset(&s_sigaction.sa_mask, SIGUSR1);
	sigaddset(&s_sigaction.sa_mask, SIGUSR2);
	s_sigaction.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &s_sigaction, 0);
		sigaction(SIGUSR2, &s_sigaction, 0);
		pause();
	}
	return (0);
}
