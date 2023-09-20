/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:47:14 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/03 14:53:35 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FALSE 0
# define TRUE 1
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	bool			end;
	long long int	strv;
	struct s_rules	*rules;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
}	t_philo;

typedef struct s_rules
{
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_must_eat;
	bool			isdeath;
	long long int	start;
	t_philo			*philo;
	pthread_mutex_t	philo_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	must_eat_mutex;
}	t_rules;

/* philo.c */
void		ft_init_arg(int ac, char **av, t_rules *rules);
void		init_philo(t_rules *rules);
void		init_mutex(t_rules *rules);

/* check.c */
int			ft_check_arg(int ac, char **av);
bool		check_mutex(int flag, t_philo *philo);

/* manage.c*/
void		*ft_meal(void *philo);
void		ft_starving(t_philo *philo);
int			ft_take_fork(t_philo *philo);
void		ft_routine(t_philo *philo);
void		ft_death(t_philo *philo);

/* thread.c */
void		ft_thread(t_rules *rules);
void		ft_monitor(t_rules *rules);
int			ft_finish(t_philo *philo);
void		ft_exit(t_rules *rules);

/* utils.c */
long long	ft_time(void);
void		my_sleep(long long time);
void		ft_message(t_philo *ph, char *msg);
int			ft_isspace(char c);
int			ft_atoi(const char *str);

/* utils2.c */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_error(char *err);

#endif