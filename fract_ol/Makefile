# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:56:48 by acuomo            #+#    #+#              #
#    Updated: 2023/03/20 14:56:50 by acuomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC			=	utils.c colours.c manage.c fractol.c maths.c write.c init.c

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

MATH_UTILS	=	./math_utils/math_utils.a

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra

$(NAME)		:	$(OBJ)
				make -C ./math_utils
				make -C ./mlx
				@mv mlx/libmlx.dylib .
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(MATH_UTILS)
				@clear
				@echo "Compilation successful!"

all			:	$(NAME)

clean		:
				$(RM) $(OBJ)

clean.all	:	clean
				make clean -C ./math_utils
				make clean -C ./mlx

fclean		:	clean
				$(RM) $(OBJ)
				$(RM) $(NAME)
				$(RM) libmlx.dylib

fclean.all	:	fclean
				make fclean -C ./math_utils
				make clean -C ./mlx

re			:	fclean $(NAME)

re.all		:	fclean.all all

debug		:	$(OBJ)
				make -C ./math_utils
				make -C ./mlx
				@mv mlx/libmlx.dylib .
				$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(MLX) $(MATH_LIB) $(LIBFT)

.PHONY		: all clean fclean re
