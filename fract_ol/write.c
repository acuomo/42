/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:57:13 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/20 15:26:09 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_calls(void)
{
	ft_putstr_fd("Please write the function you want:\n", 2);
	ft_putstr_fd("1)\tmandelbrot [define the exponent too!]\n", 2);
	ft_putstr_fd("2)\tjulia\n", 2);
	ft_putstr_fd("3)\tburning_ship\n", 2);
	ft_putstr_fd("\n\n\nEx.:\t\"./fractol mandelbrot 5\"", 2);
	exit(0);
}

void	print_intro(void)
{
	ft_putstr_fd("Welcome on board of the magician world of Fract-olz!\n", 1);
	ft_putstr_fd("Move in this complex world.\n", 1);
}

void	print_expl(t_env e)
{
	ft_putstr_fd("\nSeems like you chose ", 1);
	if (e.var.julia.x)
	{
		ft_putstr_fd("Julia!!!\n\nYou're actually watching Mandelbrot ", 1);
		ft_putstr_fd("set's primitive, with a constant set.\n", 1);
		ft_putstr_fd("If you wish, close this window, open Mandy set", 1);
		ft_putstr_fd(", click on the window and see the magic!", 1);
	}
	else if (e.var.burning)
	{
		ft_putstr_fd("The majestic Burning Ship!\n\n", 1);
		ft_putstr_fd("Did you know this is a trivial Mandelbrot set?\n", 1);
		ft_putstr_fd("Are any numbers positive? The power of math !!!\n", 1);
	}
	else
	{
		ft_putstr_fd("the mother of everything,the Mandelbrot set!\n", 1);
		ft_putstr_fd("\nClick any point and watch its respective", 1);
		ft_putstr_fd(" primitive function, which always ", 1);
		ft_putstr_fd("happens to be a Julia set with ", 1);
		ft_putstr_fd("its constant set to that point you clicked!", 1);
		ft_putstr_fd("You're able to see any Julia set you want :)\n", 1);
		ft_putstr_fd("You can reset the window and return to Mandy!\n", 1);
	}
}

void	print_commands(t_env e)
{
	ft_putstr_fd("\n\n\n", 1);
	ft_putstr_fd("\n\n\t\t**** COMMANDS ****\n\n", 1);
	ft_putstr_fd("CLICK ON:\t\t\t\tto:\n", 1);
	ft_putstr_fd("ARROWS:\t\t\t\t\tmove inside the map\n", 1);
	ft_putstr_fd("1, 2, 3, 4, 5, 0:\t\t\tchange the colours\n", 1);
	ft_putstr_fd("[space]\t\t||  R:\t\t\treset to the beginning\n", 1);
	ft_putstr_fd("[mouse wheel]\t|| ( +  &&  - ):\tzoom\n", 1);
	if (!e.var.burning)
		ft_putstr_fd("[left click]:\t\t\t\tpass to the respective Julia set", 1);
	ft_putstr_fd("\nESC:\t\t\t\t\tclose window\n\n", 1);
}
