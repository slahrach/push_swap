NAME = push_swap

LIB = libft/libft.a

LIBFT = libft

SRCS =  main.c check.c check2.c error.c operations.c sort_3_5.c sort.c

SRCS_B = main_b.c get_next_line.c get_next_line_utils.c \
			check.c check2.c error.c operations.c \

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	Make -C ${LIBFT}
	${CC} -o ${NAME} ${OBJS} ${LIB}

bonus : ${OBJS_B}
	Make -C ${LIBFT}
	${CC} ${OBJS_B} ${LIB} -o checker

clean :
	Make clean -C ${LIBFT}
	rm -f ${OBJS} ${OBJS_B}

fclean : clean
	Make fclean -C ${LIBFT}
	rm -f ${NAME} checker

re : fclean all bonus

%.o : %.c
	${CC} ${CFLAGS} -c $<

.PHONY: clean all fclean re bonus
