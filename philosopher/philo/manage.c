/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:47:37 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/04 17:00:13 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_meal(void *philo)
{
	t_philo	*ph;

	ph = philo;
	ft_starving(ph);
	if (ph->id % 2 == 0)
		my_sleep(ph->rules->time_to_eat);
	while (!check_mutex(0, ph))
	{
		if (ft_take_fork(ph))
			break ;
		if (!check_mutex(0, ph))
			ft_message(ph, "is eating");
		ph->eat++;
		if (ph->eat == ph->rules->n_must_eat)
		{
			pthread_mutex_lock(&ph->rules->must_eat_mutex);
			ph->end = TRUE;
			pthread_mutex_unlock(&ph->rules->must_eat_mutex);
		}
		ft_starving(ph);
		ft_routine(ph);
	}
	return (NULL);
}

void	ft_starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->philo_time);
	philo->strv = ft_time() - philo->rules->start;
	pthread_mutex_unlock(&philo->rules->philo_time);
}

int	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	if (!check_mutex(0, philo))
		ft_message(philo, "has taken a fork");
	if (philo->rules->n_of_philo == 1)
		return (1);
	pthread_mutex_lock(philo->left);
	if (!check_mutex(0, philo))
		ft_message(philo, "has taken a fork");
	return (0);
}

void	ft_routine(t_philo *philo)
{
	my_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (!check_mutex(0, philo))
		ft_message(philo, "is sleeping");
	my_sleep(philo->rules->time_to_sleep);
	if (!check_mutex(0, philo))
		ft_message(philo, "is thinking");
}

void	ft_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->die_mutex);
	philo->rules->isdeath = TRUE;
	pthread_mutex_unlock(&philo->rules->die_mutex);
}
