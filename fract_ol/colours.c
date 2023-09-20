/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:22 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/20 14:56:24 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_colour_two(int it, t_env *e)
{
	if (e->col.palette == 3)
	{
		e->col.r = (it % 255);
		e->col.g = (it * 12 % 255);
		e->col.b = 255 - (it * 15 % 255);
	}
	else if (e->col.palette == 4)
	{
		e->col.r = 255 - (it * 7 % 255);
		e->col.g = 255 - (it * 7 % 255);
		e->col.b = (it % 255);
	}
	else if (e->col.palette == 5)
	{
		e->col.r = ((int) pow(it, 2) * 30) % 255;
		e->col.g = ((int) pow(it, 2) * 80) % 255;
		e->col.b = (it * 40) % 255;
	}
	return ;
}

void	which_colour(int it, t_env *e)
{
	if (e->col.palette == 0)
	{
		e->col.r = 255 - (it % 255) * 10;
		e->col.g = 255 - (it % 255) * 10;
		e->col.b = 255 - (it % 255) * 10;
	}
	else if (e->col.palette == 1)
	{
		e->col.r = (it * 7 % 255);
		e->col.g = (it % 255);
		e->col.b = (it % 255);
	}
	else if (e->col.palette == 2)
	{
		e->col.r = (it * 2 % 255);
		e->col.g = (it * 15 % 255);
		e->col.b = (it * 50 % 255);
	}
	else
		which_colour_two(it, e);
}

void	palette(int keycode, t_env *e)
{
	if (keycode == 29)
		e->col.palette = 0;
	if (keycode == 18)
		e->col.palette = 1;
	if (keycode == 19)
		e->col.palette = 2;
	if (keycode == 20)
		e->col.palette = 3;
	if (keycode == 21)
		e->col.palette = 4;
	if (keycode == 23)
		e->col.palette = 5;
	print_pxl(e);
}
