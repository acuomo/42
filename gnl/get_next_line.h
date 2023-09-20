/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:01:11 by acuomo            #+#    #+#             */
/*   Updated: 2022/10/26 15:42:35 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *store);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *store, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_newline(char *store);
char	*ft_final_line(char *store);

#endif
