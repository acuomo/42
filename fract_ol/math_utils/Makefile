# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:57:26 by acuomo            #+#    #+#              #
#    Updated: 2023/03/20 14:57:28 by acuomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	math_utils.a

SRC		=	basic.c complex.c\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -rf

CFLAGS	=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJ)
			ar rc ${NAME} ${OBJ}

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)
