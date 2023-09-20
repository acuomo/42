/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:47:29 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/03 13:05:18 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread(t_rules *rules)
{
	int		i;

	i = 0;
	rules->start = ft_time();
	while (i < rules->n_of_philo)
	{
		pthread_create(&rules->philo[i].thread,
			NULL, ft_meal, &rules->philo[i]);
		i++;
	}
	ft_monitor(rules);
	i = 0;
	while (i < rules->n_of_philo)
	{
		pthread_join(rules->philo[i].thread, NULL);
		i++;
	}
	ft_exit(rules);
}

void	ft_monitor(t_rules *rules)
{
	t_philo	*ph;

	ph = rules->philo;
	while (1)
	{
		if (ft_finish(ph) == 1 || check_mutex(0, rules->philo))
			break ;
	}
}

int	ft_finish(t_philo *philo)
{
	int	tmp;
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < philo->rules->n_of_philo)
	{
		pthread_mutex_lock(&philo->rules->philo_time);
		tmp = ft_time() - philo->rules->start - philo[i].strv;
		pthread_mutex_unlock(&philo->rules->philo_time);
		if (tmp > philo->rules->time_to_die)
		{
			ft_death(philo);
			usleep(2000);
			ft_message(philo, "has died");
			return (1);
		}
		if (check_mutex(1, &philo[i]))
			check++;
		i++;
	}
	if (check == philo->rules->n_of_philo)
		ft_death(philo);
	return (0);
}

void	ft_exit(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_of_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->lock);
	pthread_mutex_destroy(&rules->die_mutex);
	pthread_mutex_destroy(&rules->must_eat_mutex);
	pthread_mutex_destroy(&rules->philo_time);
	free(rules->philo);
	free(rules->forks);
}
