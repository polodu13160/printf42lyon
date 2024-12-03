.PHONY = bonus all clean fclean re
CC = cc
FLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)
NAME = libftprintf.a
SRCS = ft_printf_format.c ft_printf.c ft_itoa_unsigned.c ft_print_hexa.c
OBJLIBFT = $(SRCS:libft/%.c=libft/%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

%.o: %.c libftprintf.h $(LIBFT)
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


all: ${NAME}
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re: 
	${MAKE} fclean 
	${MAKE} all	





















