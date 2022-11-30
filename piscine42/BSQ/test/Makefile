NAME = bsq

SRC = include/check_map.c include/map_check.c ft_split.c get_map.c init_print_tab.c sq_made.c main.c

OBJECT = $(SRC:.c=.o)

all: ${NAME}

%.o:	%.c
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}: ${OBJECT}
	gcc -Wall -Wextra -Werror ${OBJECT} -o ${NAME}


clean:
	/bin/rm -f ${OBJECT}

fclean : clean
	/bin/rm -f ${NAME}

re: fclean all

