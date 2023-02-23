# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:05:24 by jde-la-f          #+#    #+#              #
#    Updated: 2023/02/16 10:09:47 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/main.c src/ft_libft_utils.c src/ft_philosopher.c src/utils.c
		
OBJ = $(SRC:.c=.o)

CC	= cc

CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -I/usr/include -c $< -o $@ -g 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
