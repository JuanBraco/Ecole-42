# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:41:05 by avast             #+#    #+#              #
#    Updated: 2023/03/22 14:31:17 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_free_str.c \
	ft_free_strtab.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_printf_err.c \
	ft_printf_fd.c \
	ft_printf_utils.c \
	ft_printf_err_utils.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_putstrtab.c \
	ft_split.c \
	ft_split_in_two.c \
	ft_strcapitalize.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin_three.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strreplace.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strtab_size.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tabdup.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ) && ranlib $(NAME)

$(OBJ):
	@gcc -Wall -Wextra -Werror -c $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean:clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re