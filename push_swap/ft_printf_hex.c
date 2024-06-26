/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:28:27 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/27 14:28:44 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_unsigned_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

int	ft_hex_putnbr(unsigned int nb, char *hex)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_hex_putnbr(nb / 16, hex);
	i += ft_putchar(hex[nb % 16]);
	return (i);
}

int	ft_pt_putnbr(unsigned long nb, char *hex)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_pt_putnbr(nb / 16, hex);
	i += ft_putchar(hex[nb % 16]);
	return (i);
}

int	ft_print_pt_pn(unsigned long nb, char *hex)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_pt_putnbr(nb, hex);
	return (i);
}
