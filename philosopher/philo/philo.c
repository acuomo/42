/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:47:03 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/03 12:50:28 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_arg(int ac, char **av, t_rules *rules)
{
	int	i;

	i = 0;
	rules->n_of_philo = ft_atoi(av[1]);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->n_of_philo);
	rules->philo = malloc(sizeof(t_philo) * rules->n_of_philo);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->isdeath = FALSE;
	if (ac == 6)
		rules->n_must_eat = ft_atoi(av[5]);
	else
		rules->n_must_eat = -1;
	while (i < rules->n_of_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_of_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].eat = 0;
		rules->philo[i].end = FALSE;
		rules->philo[i].rules = rules;
		rules->philo[i].left = &rules->forks[i];
		rules->philo[i].right = &rules->forks[i + 1];
		if (i == rules->n_of_philo - 1)
			rules->philo[i].right = &rules->forks[0];
		i++;
	}
}

void	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_init(&rules->philo_time, NULL);
	pthread_mutex_init(&rules->die_mutex, NULL);
	pthread_mutex_init(&rules->lock, NULL);
	pthread_mutex_init(&rules->must_eat_mutex, NULL);
}
