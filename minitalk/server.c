/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:14:24 by acuomo            #+#    #+#             */
/*   Updated: 2022/11/10 14:44:44 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

void	ft_read(int sig, siginfo_t *info, void *helper)
{
	static char				c = 0;
	static int				i = 0;
	pid_t					c_pid;

	(void)helper;
	c_pid = info->si_pid;
	if (sig == SIGUSR1)
		c = c | 1;
	if (++i == 8)
	{
		if (c == 0)
			kill(c_pid, SIGUSR1);
		i = 0;
		write (1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	client;

	client.sa_sigaction = ft_read;
	client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	ft_putstr_fd("Server PID:\n", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nMandami un segnale perfavore !!!\n", 1);
	while (1)
		pause();
	return (0);
}
