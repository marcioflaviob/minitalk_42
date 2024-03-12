/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:45:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/12 01:18:24 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

// int	get_char(int sig)
// {
// 	static int		bits;
// 	static int		i;
// 	static char		c;
// 	char			temp;

// 	// if (sig == SIGUSR2)
// 	// 	write(1, "1", 1);
// 	// else
// 	// 	write(1, "0", 1);
// 	if (sig == SIGUSR2)
// 		c |= 1;
// 	bits++;
// 	if (bits == 8)
// 	{
// 		// write(1, ".", 1);
// 		temp = c;
// 		c = 0;
// 		bits = 0;
// 		i = 0;
// 		return (temp);
// 	}
// 	else
// 		c <<= 1;
// 	return (-1);
// }

// // char	*str_builder(int sig, int len, siginfo_t *info)
// void	sig_handler(int sig, siginfo_t *info, void *context)
// {
// 	static char	*str;
// 	char		c;

// 	(void) context;
// 	c = get_char(sig);
// 	if (c == -1)
// 	{
// 		kill(info->si_pid, SIGUSR1);
// 		// write(1, "here", 4);
// 		return ;
// 	}
// 	else if (c == '\0')
// 	{
// 		ft_putstr_fd(str, 1);
// 		free(str);
// 		str = NULL;
// 		kill(info->si_pid, SIGUSR2);
// 	}
// 	else
// 	{
// 		// write(1, "aaa", 3);
// 		// write(1, &c, 1);
// 		str = ft_strjoin(str, &c);
// 		kill(info->si_pid, SIGUSR1);
// 	}
// }

// // int	len_calc(int sig)
// // {
// // 	static int	c;
// // 	static int	i;
// // 	static char	*len;
// // 	int			temp;

// // 	if (!len)
// // 	{
// // 		len = (char *) ft_calloc(11, sizeof(char));
// // 		if (!len)
// // 			return (0);
// // 	}
// // 	c = get_char(sig);
// // 	while (c == -1)
// // 		return (0);
// // 	while (c != '\0')
// // 	{
// // 		len[i++] = (char) c;
// // 		return (0);
// // 	}
// // 	len[i] = 0;
// // 	i = 0;
// // 	temp = ft_atoi(len);
// // 	free(len);
// // 	len = NULL;
// // 	return (temp);
// // }

// // void	sig_handler(int sig, siginfo_t *info, void *context)
// // {
// // 	static int	len;
// // 	char		*str;

// // 	(void) context;
// // 	if (!len)
// // 	{
// // 		len = len_calc(sig, info);
// // 		if (!len)
// // 			return ;
// // 		return ;
// // 	}
// // 	str = str_builder(sig, len, info);
// // 	if (!str)
// // 		return ;
// // 	len = 0;
// // 	ft_putstr_fd(str, 1);
// // 	free(str);
// // 	str = NULL;
// // 	kill(info->si_pid, SIGUSR2);
// // }

// int	main(void)
// {
// 	struct sigaction	s_sigaction;

// 	ft_putstr_fd("PID: ", 1);
// 	ft_putnbr_fd(getpid(), 1);
// 	ft_putchar_fd('\n', 1);
// 	s_sigaction.sa_sigaction = sig_handler;
// 	sigemptyset(&s_sigaction.sa_mask);
// 	sigaddset(&s_sigaction.sa_mask, SIGUSR1);
// 	sigaddset(&s_sigaction.sa_mask, SIGUSR2);
// 	s_sigaction.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &s_sigaction, 0);
// 	sigaction(SIGUSR2, &s_sigaction, 0);
// 	while (1)
// 		pause();
// 	return (0);
// }

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
