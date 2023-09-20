/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:13:52 by acuomo            #+#    #+#             */
/*   Updated: 2022/11/16 15:37:01 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

void	ft_error(void)
{
	ft_putstr_fd("-> 404 Error 404 <-\n", 1);
	exit (1);
}

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("The message has been recived !\n", 1);
}

void	ft_send_bits(int pid, int *arr)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (arr[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	ft_str_anal(int pid, char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_convstr(str[i], arr);
		ft_send_bits(pid, arr);
		usleep(100);
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
	free(arr);
}

int	main(int argc, char **argv)
{
	pid_t	spid;
	int		*arr;

	if (argc != 3 || !ft_printisdigit(argv[1]))
		ft_error();
	signal(SIGUSR1, ft_received);
	spid = ft_atoi(argv[1]);
	arr = (int *)malloc(8 * sizeof(int));
	if (!arr)
		return (0);
	ft_str_anal(spid, argv[2], arr);
	return (0);
}
