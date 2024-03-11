/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/11 15:07:14 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_char(int sig, siginfo_t *info)
{
	static int				bits;
	static int				i;
	static unsigned char	c;
	unsigned char			temp;

	if (sig == SIGUSR2)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		temp = c;
		c = 0;
		bits = 0;
		i = 0;
		kill(info->si_pid, SIGUSR1);
		return ((int) temp);
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
	return (-1);
}

char	*str_builder(int sig, int len, siginfo_t *info)
{
	static char	*str;
	char		*temp;
	static int	pos = 0;
	int			c;

	if (!str)
	{
		str = (char *) malloc ((len + 1) * sizeof(char));
		if (!str)
			exit(1);
	}
	c = get_char(sig, info);
	while (c == -1)
		return (NULL);
	while (c != '\0')
	{
		str[pos++] = (unsigned char) c;
		return (NULL);
	}
	str[pos++] = 0;
	pos = 0;
	c = 0;
	temp = ft_strdup(str);
	(free(str), str = NULL);
	return (temp);
}

int	len_calc(int sig, siginfo_t *info)
{
	static int	c;
	static int	i;
	static char	*len;
	int			temp;

	if (!len)
	{
		len = (char *) ft_calloc(11, sizeof(char));
		if (!len)
			return (0);
	}
	c = get_char(sig, info);
	while (c == -1)
		return (0);
	while (c != '\0')
	{
		len[i++] = (char) c;
		return (0);
	}
	len[i] = 0;
	i = 0;
	temp = ft_atoi(len);
	free(len);
	len = NULL;
	return (temp);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	len;
	char		*str;

	(void) context;
	if (!len)
	{
		len = len_calc(sig, info);
		if (!len)
			return ;
		return ;
	}
	str = str_builder(sig, len, info);
	if (!str)
		return ;
	len = 0;
	ft_putstr_fd(str, 1);
	kill(info->si_pid, SIGUSR2);
	free(str);
	str = NULL;
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
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
