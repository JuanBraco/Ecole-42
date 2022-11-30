# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:40:13 by jde-la-f          #+#    #+#              #
#    Updated: 2022/09/30 09:49:32 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJECT = $(SRC:.c=.o)

HEADERS = includes/

all: ${NAME}

%.o:	%.c
	gcc -Wall -Wextra -Werror -I ${HEADERS}  -c $< -o $(<:.c=.o)

${NAME}: ${OBJECT}
	ar -rc libft.a ${OBJECT}

clean:
	/bin/rm -f ${OBJECT}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all
