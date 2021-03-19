# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 05:26:56 by nabouzah          #+#    #+#              #
#    Updated: 2019/06/21 18:13:21 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CF = errors.c shifters.c tetris_checker.c list.c map.c solve.c
OBJ = errors.o shifters.o tetris_checker.o list.o map.o solve.o main.o

all : $(NAME)

$(NAME) :
	make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -c $(CF)
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) $(OBJ) -I libft/includes libft/libft.a

clean :
	rm -f $(OBJ) && make -C libft/ clean

fclean : clean
	rm -f $(NAME) && make -C libft/ fclean

re : fclean all
