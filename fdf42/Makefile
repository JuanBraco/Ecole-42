# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:40:13 by jde-la-f          #+#    #+#              #
#    Updated: 2023/01/31 10:25:18 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/main.c src/color.c src/utils2.c src/pixel.c src/read.c src/utils.c\
		src/key.c
		
OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ./libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C ./libft fclean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
