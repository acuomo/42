/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:57:21 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/22 15:32:51 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include <math.h>

typedef struct s_cp
{
	double	x;
	double	y;
}	t_cp;

t_cp	ft_new_cp(double x, double y);
t_cp	ft_add(t_cp a, t_cp b);
t_cp	ft_sub(t_cp a, t_cp b);
void	ft_mult_const(t_cp *a, double c);

t_cp	ft_mult(t_cp a, t_cp b);
t_cp	ft_div(t_cp a, t_cp b);
t_cp	ft_power(t_cp a, int n);
void	ft_sqr_mandelbrot(t_cp *a, double real_c, double img_c);

#endif