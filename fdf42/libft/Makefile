# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:40:13 by jde-la-f          #+#    #+#              #
#    Updated: 2023/01/25 10:56:59 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isprint.c \
		ft_isdigit.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_isascii.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc libft.a $(OBJ) $(BONUS_OBJ)

.PHONY : all clean fclean re bonus
