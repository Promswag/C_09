# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 11:54:01 by gbaumgar          #+#    #+#              #
#    Updated: 2022/01/26 13:38:34 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs
INC_DIR = ./includes

SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC		= ${SRCS:%=./srcs/%}

OBJS	= ${SRC:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: libft.a

libft.a: ${OBJS}
	ar rc libft.a ${OBJS}

${OBJS}: ${SRC}
	$(CC) -c -I./includes/ -o $@ $< $(CFLAGS)

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS}
	rm -f libft.a
	
re:	fclean all
