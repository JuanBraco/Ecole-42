# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:05:24 by jde-la-f          #+#    #+#              #
#    Updated: 2023/02/12 11:32:30 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/main.c src/ft_split.c src/ft_strjoin.c src/utils.c src/ft_error.c
		
OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -I/usr/include -c $< -o $@ -g

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
