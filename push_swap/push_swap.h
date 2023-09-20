/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:13:11 by acuomo            #+#    #+#             */
/*   Updated: 2023/03/31 12:31:09 by acuomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

typedef struct s_curr {
	int	cur_a;
	int	cur_b;
}				t_curr;

typedef struct s_check {
	int	ac;
	int	trigger;
	int	i;
	int	j;
}				t_check;

typedef struct s_topush
{
	int	count_moves;
	int	index_a;
	int	index_b;
	int	tmp_moves;
}				t_topush;

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	current_a;
	int	current_b;
	int	max_b;
	int	min_b;
	int	*moves;
	int	*tmp_moves;
	int	index_maxa;
	int	index_mina;
	int	index_maxb;
	int	index_minb;
}			t_stack;

/* utils.c */
int			ft_atoi(const char *str);
int			ft_strlen(char *s);
char		*ft_strchr_gnl(char *s, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);

/* ft_printf.c */
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nb);
int			ft_unsigned_putnbr(unsigned int nb);
int			ft_hex_putnbr(unsigned int nb, char *hex);
int			ft_pt_putnbr(unsigned long nb, char *hex);
int			ft_print_pt_pn(unsigned long nb, char *hex);
int			ft_check_type(const char *s, int i, va_list args);
int			ft_printf(const char *s, ...);

/* swap.c */
void		sa(t_stack *stack, int p);
void		sb(t_stack *stack, int p);
void		ss(t_stack *stack, int p);

/* push.c */
void		pb(t_stack *stack, int p);
void		pa(t_stack *stack, int p);

/* rotate.c */
void		ra(t_stack *stack, int p);
void		rb(t_stack *stack, int p);
void		rr(t_stack *stack, int p);

/* reverse.c */
void		rra(t_stack *stack, int p);
void		rrb(t_stack *stack, int p);
void		rrr(t_stack *stack, int p);

/* check and fill STACK_A */
/*******************************************************************/
/* check_input.c */
t_stack		*ft_check_stack(char *s, t_stack *stack, t_check c);
void		ft_fill_stack(char *s, t_stack *stack, t_check c);
t_stack		*ft_check_av(char **av, t_stack *stack, t_check c);
void		ft_fill_stack_2(char **av, t_stack *stack, t_check c);
void		ft_check_doubles(t_stack *stack);

/* check_sort.c */
void		ft_check_init_sort(t_stack *stack);
t_stack		*ft_init(char **av, int ac, t_stack *stack, int k);

/* check_push_a */
t_curr		ft_mid_stacks(t_stack *stack);
void		ft_sta_maj_stb_1(t_stack *stack, int cur_a);
void		ft_sta_maj_stb_2(t_stack *stack, int cur_a, int i_topa, int i);
void		ft_stb_maj_sta_1(t_stack *stack, int cur_a);
void		ft_stb_maj_sta_2(t_stack *stack, int cur_a, int i_topa, int i);

/* sorting_a.c */
void		ft_sorting_a(t_stack *stack);
int			ft_find_next_top_a(t_stack *stack);
void		ft_pushing_to_a(t_stack *stack);
void		final_sorting(t_stack *stack);
void		ft_find_maxmin_a(t_stack *stack);

/* sorting function to push into STACK_B */
/*******************************************************************/
int			ft_sorting(t_stack *stack);
int			ft_first(t_stack *stack);

/* count_move_to_b*/
int			ft_find_index_s_b(t_stack *stack, int top_b);
t_topush	ft_find_max_moves(t_stack *stack, int i, int tmp_b,
				t_topush topush);
int			ft_next_topb(t_stack *stack, int i);
t_topush	ft_count_moves(t_stack *stack);

/* pushing_to_b.c */
void		ft_realsort(t_stack	*stack, t_topush topush);
void		ft_timetopush_under_b(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_over_b(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_mix_1(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_mix_2(t_stack	*stack, t_topush topush, int i);

/* check_to_b*/
t_topush	ft_new_cheapest(int i, int tmp_b, t_topush topush);
t_topush	ft_index_under(t_stack *stack, int i, int tmp_b, t_topush topush);
t_topush	ft_index_over(t_stack *stack, int i, int tmp_b, t_topush topush);

/* external */
/*******************************************************************/
/* maxmin.c */
void		ft_check_maxmin(t_stack *stack);

/* error.c */
void		ft_error_prev(t_stack *stack);
void		ft_error(t_stack *stack);
void		ft_close(t_stack *stack);
void		ft_close_init(t_stack *stack);
void		ft_error2(t_stack *stack);

#endif