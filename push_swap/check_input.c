/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:04:50 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/30 17:12:25 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_check_stack(char *s, t_stack *stack, t_check c)
{
	stack = malloc(sizeof(t_stack));
	stack->current_a = 0;
	while (s[c.i])
	{
		if (!((s[c.i] >= '0' && s[c.i] <= '9') || s[c.i] == 32
				|| s[c.i] == '-'))
			ft_error_prev(stack);
		if (s[c.i] == 32)
			c.trigger = 1;
		if (c.trigger == 1 && ((s[c.i] >= '0' && s[c.i] <= '9')
				|| s[c.i] == '-'))
		{
			stack->current_a++;
			c.trigger = 0;
		}
		c.i++;
	}
	return (stack);
}

void	ft_fill_stack(char *s, t_stack *stack, t_check c)
{
	int	counter;

	counter = 0;
	stack->stack_a = (int *)malloc(stack->current_a * sizeof(int));
	stack->stack_b = (int *)malloc(stack->current_a * sizeof(int));
	while (s[c.i])
	{
		if (s[c.i] == 32)
			c.trigger = 1;
		if (c.trigger == 1 && ((s[c.i] >= '0' && s[c.i] <= '9')
				|| s[c.i] == '-'))
		{
			if (ft_atoi(s + c.i) < -2147483647)
				ft_error(stack);
			if (ft_atoi(s + c.i) > 2147483646)
				ft_error(stack);
			stack->stack_a[counter] = ft_atoi(s + c.i);
			counter++;
			c.trigger = 0;
		}
		c.i++;
	}
}

t_stack	*ft_check_av(char **av, t_stack *stack, t_check c)
{
	c.i = 1;
	stack = malloc(sizeof(t_stack));
	stack->current_a = 0;
	while (c.i < c.ac)
	{
		c.j = 0;
		while (c.j < ft_strlen(av[c.i]))
		{
			if (!((av[c.i][c.j] >= '0' && av[c.i][c.j] <= '9')
				|| av[c.i][c.j] == '-'))
				ft_error_prev(stack);
			if (c.trigger == 0)
				c.j++;
			else
			{
				c.trigger = 0;
				stack->current_a++;
				c.j++;
			}
		}
		c.trigger = 1;
		c.i++;
	}
	return (stack);
}

void	ft_fill_stack_2(char **av, t_stack *stack, t_check c)
{
	c.i = 1;
	stack->stack_a = (int *)malloc(stack->current_a * sizeof(int));
	stack->stack_b = (int *)malloc(stack->current_a * sizeof(int));
	while (c.i < c.ac)
	{
		c.j = 0;
		while (c.j < ft_strlen(av[c.i]))
		{
			if (c.trigger == 0)
				c.j++;
			else
			{
				c.trigger = 0;
				if (ft_atoi(av[c.i]) < -2147483647)
					ft_error(stack);
				if (ft_atoi(av[c.i]) > 2147483646)
					ft_error(stack);
				stack->stack_a[c.i - 1] = ft_atoi(av[c.i]);
				c.j++;
			}
		}
		c.trigger = 1;
		c.i++;
	}
}

void	ft_check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (stack->current_a == 1)
		ft_close(stack);
	while (i < stack->current_a - 1)
	{
		while (stack->stack_a[i] != stack->stack_a[j] && j < stack->current_a)
		{
			j++;
			if (i == j)
				j++;
		}
		if (stack->stack_a[i] == stack->stack_a[j] && j < stack->current_a)
			ft_error(stack);
		j = 0;
		i++;
	}
}
