/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:58 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/21 13:27:30 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cp	virtual_to_real(t_vars mlx, int x, int y)
{
	t_cp	res;

	res.x = mlx.virt_min.x + ((x * (mlx.virt_max.x - mlx.virt_min.x)) / WIDTH);
	res.y = mlx.virt_min.y + ((y * (mlx.virt_max.y - mlx.virt_min.y)) / WIDTH);
	return (res);
}

t_cp	mandelbrot_calc(t_bool var, t_cp val, t_cp constant)
{
	val = ft_power(val, var.mandelbrot);
	val = ft_add(val, constant);
	return (val);
}

int	ft_mandelbrot_math(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cp		val;
	t_cp		constant;

	i = 0;
	val.x = 0.0;
	val.y = 0.0;
	constant = virtual_to_real(mlx, x, y);
	while (i < 20)
	{
		val = mandelbrot_calc(var, val, constant);
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0 * 2.0)
			break ;
		i++;
	}
	return (i);
}

int	ft_julia(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cp		val;
	t_cp		constant;

	i = 0;
	val = virtual_to_real(mlx, x, y);
	constant = var.julia;
	while (i < 20)
	{
		val = mandelbrot_calc(var, val, constant);
		if (pow (val.x, 2) + pow (val.y, 2) > 2.0 * 2.0)
			break ;
		i++;
	}
	return (i);
}

int	ft_burning_ship(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cp		val;
	t_cp		constant;

	i = 0;
	val.x = 0.0;
	val.y = 0.0;
	constant = virtual_to_real(mlx, x, y);
	while (i < 20)
	{
		val = mandelbrot_calc(var, val, constant);
		val.x = fabsl(val.x);
		val.y = fabsl(val.y);
		if (pow (val.x, 2) + pow (val.y, 2) > 2.0 * 2.0)
			break ;
		i++;
	}
	return (i);
}
