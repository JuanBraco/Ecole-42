NAME = bsq

SRC = srcs/check_map.c srcs/map_check.c srcs/get_map.c srcs/solve.c srcs/dimensions.c srcs/gen_fct.c main.c

OBJECT = $(SRC:.c=.o)

all: ${NAME}

%.o:	%.c
	gcc -g3 -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}: ${OBJECT}
	gcc -g3 -Wall -Wextra -Werror ${OBJECT} -o ${NAME}


clean:
	/bin/rm -f ${OBJECT}

fclean : clean
	/bin/rm -f ${NAME}

re: fclean all

