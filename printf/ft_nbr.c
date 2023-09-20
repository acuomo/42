/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:22:33 by acuomo            #+#    #+#             */
/*   Updated: 2022/08/05 12:03:41 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	l;

	l = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		l = ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		l = l + ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (l + 1);
}

int	ft_putuns(unsigned int n)
{
	int	l;

	l = 0;
	if (n >= 10)
	{
		l += ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
	return (l + 1);
}
