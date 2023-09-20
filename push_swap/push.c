/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:10:51 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/28 16:44:28 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack, int p)
{
	int	i;

	i = stack->current_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->current_a++;
	stack->stack_a[0] = stack->stack_b[0];
	i = 1;
	while (i < stack->current_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->current_b--;
	if (p == 1)
		ft_printf("pa\n");
}

void	pb(t_stack *stack, int p)
{
	int	i;

	i = stack->current_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->current_b++;
	stack->stack_b[0] = stack->stack_a[0];
	i = 1;
	while (i < stack->current_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->current_a--;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("pb\n");
}
