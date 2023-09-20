/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:34 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/22 15:10:17 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./math_utils/math_utils.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef DIM

#  define DIM
#  define WIDTH 640
#  define HEIGHT 640

# endif

typedef struct s_bool
{
	int		mandelbrot;
	t_cp	julia;
	int		burning;
}	t_bool;

typedef struct s_pxl
{
	int	palette;
	int	r;
	int	g;
	int	b;
}	t_pxl;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_cp		virt_max;
	t_cp		virt_min;
	double		zoom;
}	t_vars;

typedef struct s_env
{
	int		(*function)(t_vars mlx, t_bool var, int x, int y);
	t_data	img;
	t_pxl	col;
	t_vars	mlx;
	t_bool	var;
	int		argc;
	char	**argv;
}	t_env;

//colours.c
void			which_colour(int it, t_env *e);
void			which_colour_two(int it, t_env *e);
void			palette(int keycode, t_env *e);
//maths.c
t_cp			virtual_to_real(t_vars mlx, int x, int y);
t_cp			mandelbrot_calc(t_bool var, t_cp val, t_cp constant);
int				ft_mandelbrot_math(t_vars mlx, t_bool var, int x, int y);
int				ft_julia(t_vars mlx, t_bool var, int x, int y);
int				ft_burning_ship(t_vars mlx, t_bool var, int x, int y);
//manage.c
int				ft_mouse_manage(int keycode, int x, int y, t_env *e);
int				new_julia(t_env *e, int x, int y);
void			move_map_arrows(int keycode, t_env *e);
void			ft_zoom(int x, int y, t_env *e, int isplus);
int				ft_command(int keycode, t_env *e);
//init.c
void			which_function(t_env *e);
void			ft_init_e(t_env *e);
//print.c
void			print_calls(void);
void			print_intro(void);
void			print_expl(t_env e);
void			print_commands(t_env e);
//fractol.c
void			ft_fun1(t_env *e);
void			ft_fun2(t_env *e);
int				destroy_win(t_env *e);
void			my_mlx_pixel_put(t_env *e, int x, int y);
void			print_pxl(t_env *e);
//utils.c
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);

#endif
