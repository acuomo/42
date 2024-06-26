/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:17:49 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/27 15:18:07 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorting(t_stack *stack)
{
	int	len;

	if (stack->current_a == 3)
	{
		ft_sorting_a(stack);
		ft_close(stack);
	}
	len = 0;
	len += ft_first(stack);
	return (len);
}

int	ft_first(t_stack *stack)
{
	stack->current_b = 0;
	stack->min_b = 0;
	stack->max_b = 0;
	if (stack->stack_a[0] > stack->stack_a[1])
	{
		stack->min_b = stack->stack_a[1];
		stack->max_b = stack->stack_a[0];
	}
	else
	{
		stack->min_b = stack->stack_a[0];
		stack->max_b = stack->stack_a[1];
	}
	pb(stack, 1);
	pb(stack, 1);
	return (2);
}
