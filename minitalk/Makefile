# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuomo <acuomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:13:07 by acuomo            #+#    #+#              #
#    Updated: 2022/11/10 13:13:19 by acuomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT	=	client

NAME_SERVER	=	server

SRC_CLIENT	=	client.c utils.c

SRC_SERVER	=	server.c utils.c


OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)


CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror


all:			$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
		
$(NAME_SERVER):	$(OBJ_SERVER)
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)


clean:			
				$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:			clean
				$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER)

re:				fclean all

.PHONY:			all clean fclean re