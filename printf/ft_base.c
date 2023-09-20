/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:52:12 by acuomo            #+#    #+#             */
/*   Updated: 2022/08/05 12:03:16 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tohex(unsigned long num, char *hexbase)
{
	int		i;

	i = 0;
	if (num >= 16)
	{
		i += ft_tohex(num / 16, hexbase);
		ft_tohex(num % 16, hexbase);
	}
	else
		ft_putchar(hexbase[num]);
	return (i + 1);
}

int	ft_voidpointer(unsigned long p)
{
	if (p < 0)
		return (0);
	ft_putstr("0x");
	return (2 + ft_tohex(p, "0123456789abcdef"));
}

int	ft_toupper_hex(unsigned int n)
{
	return (ft_tohex(n, "0123456789ABCDEF"));
}

int	ft_tolower_hex(unsigned int n)
{
	return (ft_tohex(n, "0123456789abcdef"));
}
