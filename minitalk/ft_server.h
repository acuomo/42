/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:13:28 by acuomo            #+#    #+#             */
/*   Updated: 2022/11/10 14:48:48 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void		ft_str_anal(int pid, char *str, int *arr);
void		ft_send_bits(int pid, int *arr);
void		ft_received(int sig);
void		ft_error(void);

int			ft_printisdigit(char *s);
void		ft_read(int sig, siginfo_t *info, void *helper);

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *str);
char		ft_convbin(int *byte);
void		ft_convstr(char c, int *arr);

#endif