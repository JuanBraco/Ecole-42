# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:40:13 by jde-la-f          #+#    #+#              #
#    Updated: 2023/01/19 13:29:39 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = fct_utils.c init_list.c main.c push.c rev_rotate.c rotate.c sort.c swap.c \
		check_input.c opti_move.c cost.c position.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
