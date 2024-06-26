/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:04:08 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/30 17:15:46 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init(char **av, int ac, t_stack *stack, int k)
{
	t_check	check;

	check.ac = ac;
	check.i = 0;
	check.j = 0;
	check.trigger = 1;
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		stack = ft_check_stack(av[1], stack, check);
		ft_fill_stack(av[1], stack, check);
	}
	else
	{
		stack = ft_check_av(av, stack, check);
		ft_fill_stack_2(av, stack, check);
	}
	ft_check_doubles(stack);
	if (k == 1)
		ft_check_init_sort(stack);
	return (stack);
}

void	ft_check_init_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return ;
		i++;
	}
	if (i == stack->current_a - 1)
		ft_close_init(0);
}
