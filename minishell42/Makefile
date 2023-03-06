# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:41:55 by avast             #+#    #+#              #
#    Updated: 2023/03/03 14:56:58 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

PIPES = src/pipes/errors.c \
	src/pipes/files.c \
	src/pipes/main.c \
	src/pipes/path.c \
	src/pipes/pipes.c \


SRC = main.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/minishell.h \
	includes/pipes.h \
	includes/builtins.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft/

MAKEFLAGS += --no-print-directory

BLUE = \033[1;94m

PURPLE = \033[1;95m

GREEN = \033[1;92m

YELLOW = \033[1;93m

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I./includes -I./libft -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(INCLUDES)
	@$(CC) $(OBJ) -L$(LIBFTDIR) -lreadline -g3 -lft -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(LIBFT):
	@make -C $(LIBFTDIR) 
	@printf "$(BLUE)--------Libft.a created----------\n\n"

clean:
	@/bin/rm -f $(OBJ) *.o
	@make clean -C $(LIBFTDIR)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@/bin/rm -f $(NAME) testapo
	@make fclean -C $(LIBFTDIR)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

testapo : $(LIBFT)
	@$(CC) $(FLAGS) src/environ/*.c src/builtins/echo.c -c -I./includes -I./libft
	@$(CC) environ.o variables.o echo.o -L$(LIBFTDIR) -g3 -lft -o testapo
	@printf "$(YELLOW)------Compilation executed------\n\n"

.PHONY : all clean fclean re

