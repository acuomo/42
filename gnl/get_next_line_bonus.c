/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:17:25 by acuomo            #+#    #+#             */
/*   Updated: 2022/10/26 17:32:27 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_newline(char *store)
{
	int		i;
	char	*str;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		str[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		str[i] = store[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_final_line(char *store)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		str[j++] = store[i++];
	str[j] = '\0';
	free(store);
	return (str);
}

char	*ft_read(int fd, char *store)
{
	char	*buffer;
	int		read_result;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_result = 1;
	while (!ft_strchr(store, '\n') && read_result != 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			if (store)
				free(store);
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		store = ft_strjoin(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[1024];

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	store[fd] = ft_read(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_newline(store[fd]);
	if (ft_strlen(line) - ft_strlen(store[fd]) > 0)
		store[fd] = ft_final_line(store[fd]);
	else
	{
		free(store[fd]);
		store[fd] = NULL;
	}
	return (line);
}
