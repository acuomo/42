NAME		=		push_swap

NAME_B		=		checker

SRC			=		utils.c gnl.c ft_printf_dec.c ft_printf_hex.c ft_printf.c\
					check_input.c check_sort.c error.c\
					push.c reverse.c rotate.c swap.c\
					check_maxmin.c check_push_a.c check_to_b.c count_move_to_b.c\
					pushing_to_b.c sorting_a.c sorting.c push_swap.c



BONUS		=		bonus/checker.c utils.c gnl.c ft_printf_dec.c ft_printf_hex.c ft_printf.c\
					check_input.c check_sort.c error.c\
					push.c reverse.c rotate.c swap.c\
					check_maxmin.c check_push_a.c check_to_b.c count_move_to_b.c\
					pushing_to_b.c sorting_a.c sorting.c

OBJ			=		$(SRC.c=.o)

BOBJ		=		$(BONUS.c=.o)

CC			=		gcc

FLAG		=		-Wall -Werror -Wextra

all:				$(NAME)
$(NAME):			$(OBJ)
					$(CC) $(FLAGS) $(SRC) $(LIBRARY) -o $(NAME)

bonus: 				$(NAME) $(NAME_B)
$(NAME_B):			$(BOBJ)
					$(CC) $(FLAGS) $(BONUS) $(LIBRARY) -o $(NAME_B)

clean:
					rm -f $(OBJ)
					rm -f $(BOBJ)

fclean: 			clean
					rm -f $(NAME)
					rm -f $(NAME_B)

re: 				fclean all clean