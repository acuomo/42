/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:24 by acuomo            #+#    #+#             */
/*   Updated: 2022/08/05 16:31:24 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conf(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len = ft_putuns(va_arg(arg, unsigned int));
	else if (c == 'x')
		len = ft_tolower_hex(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = ft_toupper_hex(va_arg(arg, unsigned int));
	else if (c == 'p')
		len = ft_voidpointer(va_arg(arg, unsigned long));
	else if (c == '%')
		len = write (1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += ft_conf(str[++i], arg);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
