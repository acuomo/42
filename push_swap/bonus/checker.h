/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:08:22 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/31 12:25:24 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

/* gnl.c */
char		*get_line(int fd, char *line);
char		*get_new_line(char *line);
char		*new_line(char *line);
char		*get_next_line(int fd);

/* checker.c */
void		check_move(char *cmd, t_stack *stack);
int			ft_check_sort(t_stack *stack);

#endif