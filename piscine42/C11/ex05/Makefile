NAME = do-op

SRC = main.c operateur.c

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
