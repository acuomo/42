/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:41 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/20 16:21:12 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fun1(t_env *e)
{
	e->var.julia.x = 0.285;
	e->var.julia.y = 0.01;
	e->function = &ft_julia;
}

void	ft_fun2(t_env *e)
{
	e->var.burning = 1;
	e->function = &ft_burning_ship;
}

void	which_function(t_env *e)
{
	e->var.mandelbrot = 2;
	e->var.julia.x = 0;
	e->var.julia.y = 0;
	e->var.burning = 0;
	if (e->argc < 2)
		print_calls();
	else if (!ft_strncmp(e->argv[1], "mandelbrot", 10))
	{
		if (!e->argv[2])
			print_calls();
		if (e->argv[2][0] > '0' && e->argv[2][0] <= '9')
		{
			e->var.mandelbrot = ft_atoi(e->argv[2]);
			e->function = &ft_mandelbrot_math;
		}
		else
			print_calls();
	}
	else if (!ft_strncmp(e->argv[1], "julia", 5))
		ft_fun1(e);
	else if (!ft_strncmp(e->argv[1], "burning_ship", 13))
		ft_fun2(e);
	else
		print_calls();
}

void	ft_init_e(t_env *e)
{
	e->col.r = 0;
	e->col.g = 0;
	e->col.b = 0;
	e->col.palette = 0;
	e->mlx.virt_min.x = -2;
	e->mlx.virt_max.x = 2;
	e->mlx.virt_min.y = -2;
	e->mlx.virt_max.y = 2;
	e->mlx.zoom = 1.0f;
	e->img.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bits_per_pixel,
			&e->img.line_length, &e->img.endian);
}
