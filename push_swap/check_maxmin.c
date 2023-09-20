/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maxmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:13:47 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/27 15:14:10 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_maxmin(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_b)
	{
		if (stack->stack_b[i] >= stack->max_b)
		{
			stack->max_b = stack->stack_b[i];
			stack->index_maxb = i;
		}
		else if (stack->stack_b[i] < stack->min_b)
		{
			stack->min_b = stack->stack_b[i];
			stack->index_minb = i;
		}
		i++;
	}
}
