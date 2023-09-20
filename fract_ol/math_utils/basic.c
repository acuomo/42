/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:57:35 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/20 15:30:23 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

t_cp	ft_new_cp(double x, double y)
{
	t_cp	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_cp	ft_add(t_cp a, t_cp b)
{
	t_cp	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

t_cp	ft_sub(t_cp a, t_cp b)
{
	t_cp	sub;

	sub.x = a.x - b.y;
	sub.y = a.y - b.y;
	return (sub);
}

void	ft_mult_const(t_cp *a, double c)
{
	a->x *= c;
	a->y *= c;
}
