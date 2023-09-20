/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:14:35 by acuomo            #+#    #+#             */
/*   Updated: 2022/11/10 14:42:49 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	c;

	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		c = *s++;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	char	c;

	if (n == -2147483648)
	{
		s = "-2";
		ft_putstr_fd(s, fd);
		n = 147483648;
	}
	if (n < 0)
	{
		s = "-";
		ft_putstr_fd(s, fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = ('0' + n);
		write (1, &c, fd);
	}
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			neg;

	neg = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		++str;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * neg);
}

int	ft_printisdigit(char *s)
{
	while (s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
		s++;
	}
	return (0);
}

void	ft_convstr(char c, int *arr)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		arr[i] = (c >> i) & 1;
		i--;
	}
}
