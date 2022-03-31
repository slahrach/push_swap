NAME = push_swap

LIB = libft/libft.a

LIBFT = libft

LPRINTF = printf/libftprintf.a

SRCS =  main.c check.c check2.c error.c operations.c sort_3_5.c sort.c

SRCS_B = main_b.c get_next_line.c get_next_line_utils.c \
			check.c check2.c error.c operations.c \

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@Make -C ${LIBFT}
	@Make -C printf
	@echo "object files are created"
	@${CC} -o ${NAME} ${OBJS} ${LIB} ${LPRINTF}
	@echo "push_swap is created"

bonus : ${OBJS_B}
	@Make -C ${LIBFT}
	@Make -C printf
	@echo "bonus object files are created"
	@${CC} ${OBJS_B} ${LIB} ${LPRINTF} -o checker
	@echo "bonus checker is created"

clean :
	@Make clean -C ${LIBFT}
	@Make clean -C printf
	@rm -f ${OBJS} ${OBJS_B}
	@echo "object files are removed"

fclean : clean
	@Make fclean -C printf
	@Make fclean -C ${LIBFT}
	@rm -f ${NAME} checker
	@echo "executables are removed"

re : fclean all

%.o : %.c
	@${CC} ${CFLAGS} -c $<

.PHONY: clean all fclean re bonus
