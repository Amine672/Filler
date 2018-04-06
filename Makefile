# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 17:42:09 by akabbouc          #+#    #+#              #
#    Updated: 2017/05/15 17:42:10 by akabbouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = players/akabbouc.filler

CC = gcc

INCLUDES = "libft/includes"

SECONDIN = "includes"

FLAGS = -Wall -Wextra -Werror -g3

SRC = 	main.c tools.c get_info.c algo.c colors.c

LIB = libft/libft.a

OBJ = $(addprefix src/,$(SRC:.c=.o))

all : $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lft -L ./libft -I $(INCLUDES) -I $(SECONDIN)

%.o:%.c
	gcc -c $(FLAGS) -I $(INCLUDES) -I $(SECONDIN) $< -o $@ 

clean :
	make -C libft/ fclean
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
