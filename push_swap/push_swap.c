/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:19:55 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/27 15:20:09 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack;
	t_topush	topush;
	int			i;
	int			len;
	int			j;

	len = 0;
	stack = ft_init(av, ac, stack, 1);
	len += ft_sorting(stack);
	j = stack->current_a;
	i = -1;
	while (++i < j - 3)
	{
		topush = ft_count_moves(stack);
		ft_realsort(stack, topush);
	}
	ft_find_maxmin_a(stack);
	ft_sorting_a(stack);
	i = stack->current_b;
	j = -1;
	while (++j < i)
		ft_pushing_to_a(stack);
	final_sorting(stack);
	ft_close(stack);
}
