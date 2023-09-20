/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:54:52 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/03 13:00:18 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_error("Insert 5 or 6 arguments\n"));
	while (av[i])
	{
		if (av[i][0] == ' ' || av[i][0] == '0' || av[i][0] == '-')
			return (ft_error("Arguments must be >0\n"));
		if (ft_strncmp("2147483647", av[i], ft_strlen(av[i])) != 0
			&& ft_strlen(av[i]) >= 10)
			return (ft_error("Arguments is greater than MAX INT\n"));
		if (ft_atoi(av[i]) < 1)
			return (ft_error("Arguments is not a number"));
		i++;
	}
	return (1);
}

bool	check_mutex(int flag, t_philo *philo)
{
	bool	tmp;

	tmp = TRUE;
	if (flag == 0)
	{
		pthread_mutex_lock(&philo->rules->die_mutex);
		tmp = philo->rules->isdeath;
		pthread_mutex_unlock(&philo->rules->die_mutex);
	}
	if (flag == 1)
	{
		pthread_mutex_lock(&philo->rules->must_eat_mutex);
		tmp = philo->end;
		pthread_mutex_unlock(&philo->rules->must_eat_mutex);
	}
	return (tmp);
}
