# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 19:22:51 by jerdos-s          #+#    #+#              #
#    Updated: 2022/08/13 17:53:49 by jerdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = ./src/
OPTION = -I$(SRC_PATH) -c
SRC =	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_puthex.c \
	ft_putnbr.c \
	ft_putnbr_unsigned.c \
	ft_putptr.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(SRCS:.c=.o)
CC = gcc


all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(OPTION) $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
