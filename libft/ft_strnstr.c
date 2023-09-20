/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:34:43 by acuomo            #+#    #+#             */
/*   Updated: 2022/05/06 19:47:19 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*n == '\0' || n == NULL)
		return ((char *) h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (n[j] == h[i + j] && i + j < len)
		{
			if (n[j + 1] == '\0')
			{
				return ((char *) h + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
