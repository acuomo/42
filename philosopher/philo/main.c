/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:49:22 by acuomo            #+#    #+#             */
/*   Updated: 2023/08/04 17:00:01 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (!ft_check_arg(ac, av))
		return (1);
	ft_init_arg(ac, av, &rules);
	init_philo(&rules);
	init_mutex(&rules);
	ft_thread(&rules);
	return (0);
}
