/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:14:47 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/27 15:15:04 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_topush	ft_index_over(t_stack *stack, int i, int tmp_b, t_topush topush)
{
	if (stack->current_b - tmp_b < stack->current_a - i)
		topush.tmp_moves = stack->current_a - i;
	else
		topush.tmp_moves = stack->current_b - tmp_b;
	return (topush);
}

t_topush	ft_index_under(t_stack *stack, int i, int tmp_b, t_topush topush)
{
	if (tmp_b >= i)
		topush.tmp_moves = tmp_b;
	else
		topush.tmp_moves = i;
	return (topush);
}

t_topush	ft_new_cheapest(int i, int tmp_b, t_topush topush)
{
	topush.index_a = i;
	topush.index_b = tmp_b;
	topush.count_moves = topush.tmp_moves;
	return (topush);
}
