/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:14:53 by acuomo            #+#    #+#             */
/*   Updated: 2022/08/05 16:14:43 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_tolower_hex(unsigned int n);
int		ft_toupper_hex(unsigned int n);
int		ft_voidpointer(unsigned long p);
int		ft_tohex(unsigned long num, char *hexbase);
int		ft_putuns(unsigned int n);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_conf(char c, va_list arg);

#endif
