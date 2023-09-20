/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:03:18 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/30 17:03:55 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_prev(t_stack	*stack)
{
	ft_printf("Error\n");
	free(stack);
	exit(0);
}

void	ft_error(t_stack *stack)
{
	ft_printf("Error\n");
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}

void	ft_error2(t_stack *stack)
{
	ft_printf("KO\n");
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}

void	ft_close(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}

void	ft_close_init(t_stack *stack)
{
	free(stack);
	exit(0);
}
