/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:15:43 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/29 17:33:50 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_topush	ft_count_moves(t_stack *stack)
{
	int			i;
	int			index_b;
	int			top_b;
	int			tmp_b;
	t_topush	topush;

	topush.index_a = 0;
	topush.index_b = 0;
	topush.count_moves = 0;
	tmp_b = 0;
	i = 0;
	topush.tmp_moves = 0;
	top_b = 0;
	while (i < stack->current_a)
	{
		top_b = ft_next_topb(stack, i);
		tmp_b = ft_find_index_s_b(stack, top_b);
		topush = ft_find_max_moves(stack, i, tmp_b, topush);
		i++;
	}
	return (topush);
}

int	ft_next_topb(t_stack *stack, int i)
{
	int	j;
	int	tmp;

	j = -1;
	tmp = 0;
	if (stack->stack_a[i] > stack->max_b || stack->stack_a[i] < stack->min_b)
	{
		return (stack->max_b);
	}
	else
	{
		while (++j < stack->current_b - 1)
		{
			if (stack->stack_a[i] < stack->stack_b[j]
				&& stack->stack_a[i] > stack->stack_b[j + 1])
			{
				tmp = j + 1;
				break ;
			}
		}
		return (stack->stack_b[tmp]);
	}
}

int	ft_find_index_s_b(t_stack *stack, int top_b)
{
	int	i;

	i = 0;
	while (i < stack->current_b)
	{
		if (stack->stack_b[i] == top_b)
			break ;
		i++;
	}
	return (i);
}

t_topush	ft_find_max_moves(t_stack *stack, int i, int tmp_b, t_topush topush)
{
	int	cur_a;
	int	cur_b;

	if ((stack->current_a % 2) != 0)
		cur_a = stack->current_a / 2 + 1;
	else
		cur_a = stack->current_a / 2;
	if ((stack->current_b % 2) != 0)
		cur_b = stack->current_b / 2 + 1;
	else
		cur_b = stack->current_b / 2;
	if (tmp_b >= cur_b && i >= cur_a)
		topush = ft_index_over(stack, i, tmp_b, topush);
	else if (tmp_b < cur_b && i < cur_a)
		topush = ft_index_under(stack, i, tmp_b, topush);
	else
	{
		if (tmp_b < cur_b && i >= cur_a)
			topush.tmp_moves = tmp_b + (stack->current_a - i);
		else
			topush.tmp_moves = i + stack->current_b - tmp_b;
	}
	if (topush.count_moves > topush.tmp_moves || i == 0)
		topush = ft_new_cheapest(i, tmp_b, topush);
	return (topush);
}
