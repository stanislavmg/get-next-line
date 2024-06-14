# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoremyk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:40:01 by sgoremyk          #+#    #+#              #
#    Updated: 2024/03/12 14:40:03 by sgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl.a

INCLUDE =	get_next_line_bonus.h

CFLAGS	=	-Wall -Wextra -Werror

SRC		=		get_next_line_bonus.c get_next_line_utils_bonus.c 

OBJ		=	$(SRC:%.c=%.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME) :	$(OBJ) $(INCLUDE) Makefile
	ar rcs $(NAME) $?

%.o		:	%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all
