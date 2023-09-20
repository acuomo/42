/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:16 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/22 15:01:01 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_win(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	write(1, "See ya!\n", 8);
	exit(0);
}

void	my_mlx_pixel_put(t_env *e, int x, int y)
{
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		e->img.addr[(x * 4) + (y * WIDTH * 4) + 2] = e->col.r;
		e->img.addr[(x * 4) + (y * WIDTH * 4) + 1] = e->col.g;
		e->img.addr[(x * 4) + (y * WIDTH * 4)] = e->col.b;
	}
}

void	print_pxl(t_env *e)
{
	int	i;
	int	j;
	int	iterations;

	i = -1;
	j = -1;
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	while (++i < HEIGHT)
	{
		while (++j < WIDTH)
		{
			iterations = e->function(e->mlx, e->var, j, i);
			which_colour(iterations, e);
			my_mlx_pixel_put(e, j, i);
		}
		j = -1;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	e.argc = argc;
	e.argv = argv;
	e.mlx.mlx = mlx_init();
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT,
			"Like on cauliflowers the fractals");
	which_function(&e);
	ft_init_e(&e);
	print_pxl(&e);
	print_intro();
	print_expl(e);
	print_commands(e);
	mlx_hook(e.mlx.win, 17, 0, destroy_win, &e);
	mlx_key_hook(e.mlx.win, ft_command, &e);
	mlx_mouse_hook(e.mlx.win, ft_mouse_manage, &e);
	mlx_loop(e.mlx.mlx);
}
