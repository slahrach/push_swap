# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 00:02:19 by slahrach          #+#    #+#              #
#    Updated: 2022/03/30 15:44:08 by slahrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = aff_char.c aff_str.c aff_base10.c aff_unsigned.c aff_base16.c \
		aff_pointer.c ft_printf.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

all : ${NAME}

${NAME} : ${OBJ}
	@${AR} ${NAME} ${OBJ}
	@echo "objects printf are made!"
	@echo "libftprintf.a is made"

clean :
	@rm -f ${OBJ}
	@echo "objects printf are removed"

fclean : clean
	@rm -f ${NAME}
	@echo "libftprintf.a is removed"

re : fclean all

%.o : %.c
	@${CC} ${CFLAGS} -c $<
	
.PHONY: clean all fclean re
