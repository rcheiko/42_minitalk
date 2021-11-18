# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 12:53:49 by rcheiko           #+#    #+#              #
#    Updated: 2021/09/29 14:49:10 by rcheiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	client

NAME2		=	server

SRCS		=	minitalk_client.c \
				ft_utils_client.c

SRCS2		=	minitalk_server.c \
				ft_utils_server.c

OBJS		=	${SRCS:.c=.o}

OBJS2		=	${SRCS2:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes


RM			=	rm -f

all:			${NAME} ${NAME2}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

$(NAME2):		${OBJS2}
				${CC} ${CFLAGS} -o ${NAME2} ${OBJS2}

clean:
				${RM} ${OBJS} ${OBJS2}

fclean:			clean
				${RM} ${NAME} ${NAME2}

re:				fclean all
