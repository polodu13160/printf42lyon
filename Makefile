.PHONY = bonus all clean fclean re
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = libft/
OBJLIBFT = $(SRCS:libft/%.c=libft/%.o)

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

%.o: %.c libftprintf.h
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} 
	ar rcs ${NAME}	${OBJS}


all: ${NAME}
clean:
	rm -f ${OBJS} ${OBJS_B}
fclean:
	${MAKE} clean 
	rm -f ${NAME}
re: 
	${MAKE} fclean 
	${MAKE} all	



