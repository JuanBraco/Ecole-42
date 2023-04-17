# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:41:55 by avast             #+#    #+#              #
#    Updated: 2023/03/23 12:43:21 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

ENVIRON = src/environ/environ_list_set.c \
	src/environ/environ_char_set.c \
	src/environ/environ_list_utils.c \
	src/environ/variable_expansion.c \

PARSING = src/parsing/parser.c \
	src/parsing/utils_pars.c \
	src/parsing/redir.c \
	src/parsing/utils_node_lst.c \
	src/parsing/utils_cmds_lst.c \

LEXER = src/lexer/lexer_utils.c \
	src/lexer/add_node.c \
	src/lexer/text_reader.c \

PIPES = src/pipes/errors.c \
	src/pipes/exec.c \
	src/pipes/files.c \
	src/pipes/path.c \
	src/pipes/pid.c \
	src/pipes/pipes.c \

BUILTINS = src/builtins/builtin_utils.c \
	src/builtins/cd.c \
	src/builtins/echo.c \
	src/builtins/env.c \
	src/builtins/exit.c \
	src/builtins/export.c \
	src/builtins/pwd.c \
	src/builtins/unset.c \

SRC = src/main.c \
	src/error.c \
	src/signal.c \
	$(PARSING) $(LEXER) $(ENVIRON) $(PIPES) $(BUILTINS)

OBJ = $(SRC:.c=.o)

INCLUDES = includes/minishell.h \


TESTAPO = test.c
TESTAPO_OBJ = $(TESTAPO:.c=.o)

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
	@/bin/rm -f $(OBJ) $(TESTAPO_OBJ)
	@make clean -C $(LIBFTDIR)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@/bin/rm -f $(NAME) testapo
	@make fclean -C $(LIBFTDIR)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

testapo : $(TESTAPO_OBJ) $(LIBFT) $(INCLUDES)
	@$(CC) $(TESTAPO) -L$(LIBFTDIR) -lreadline -g3 -lft -o testapo
	@printf "$(YELLOW)------Compilation executed------\n\n"

.PHONY : all clean fclean re

