# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 17:07:21 by aatki             #+#    #+#              #
#    Updated: 2023/02/26 16:27:03 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c\
	pipex_utils.c\
	ft_split.c

OBJC = ${SRC :.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CFLAGS}  ${SRC} -o ${NAME}

clean :
	rm -rf ${OBJC}
fclean: clean
	rm -rf ${NAME}
re : fclean all
