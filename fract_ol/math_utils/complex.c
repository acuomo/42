/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:57:30 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/20 15:33:41 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

t_cp	ft_mult(t_cp a, t_cp b)
{
	t_cp	mult;

	mult.x = (a.x * b.x) - (a.y * b.y);
	mult.y = (a.x * b.y) + (b.x * a.y);
	return (mult);
}

t_cp	ft_div(t_cp a, t_cp b)
{
	double	const_div;
	t_cp	div;

	const_div = 1 / (pow(b.x, 2) + pow(b.y, 2));
	div.x = (a.x * b.x) + (a.y * b.y);
	div.y = (a.y * b.x) - (a.x * b.y);
	ft_mult_const(&div, const_div);
	return (div);
}

void	ft_sqr_mandelbrot(t_cp *a, double real_c, double img_c)
{
	t_cp	tmp;

	tmp = *a;
	a->x = pow(tmp.x, 2) - pow(tmp.y, 2) + real_c;
	a->y = (2 * (tmp.x * tmp.y)) + img_c;
}

t_cp	ft_power(t_cp a, int n)
{
	t_cp	tmp;

	tmp = a;
	if (n == 0)
	{
		tmp.x = 1;
		tmp.y = 0;
		return (tmp);
	}
	if (n == 1)
		return (tmp);
	tmp = ft_power (tmp, n / 2);
	if (n % 2 == 0)
		return (ft_mult(tmp, tmp));
	return (ft_mult(a, ft_mult(tmp, tmp)));
}
