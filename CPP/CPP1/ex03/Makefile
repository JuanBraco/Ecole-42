# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 17:33:02 by jde-la-f          #+#    #+#              #
#    Updated: 2023/04/29 17:30:56 by jde-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = war

CC = clang++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re