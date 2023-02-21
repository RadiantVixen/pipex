# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 17:07:21 by aatki             #+#    #+#              #
#    Updated: 2023/02/21 17:51:36 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c\

OBJC = ${SRC :.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
	rm - r ${OBJC}
fclean: clean
	rm -r ${NAME}
re : fclean all
