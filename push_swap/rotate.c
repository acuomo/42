/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:24 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/28 16:48:37 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->current_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->current_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("rb\n");
}

void	rr(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->current_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->current_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("rr\n");
}
