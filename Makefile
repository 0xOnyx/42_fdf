# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 17:20:38 by jerdos-s          #+#    #+#              #
#    Updated: 2022/08/15 20:40:54 by jerdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft
OPTIONS = -I/usr/include/ -Imlx_linux -I./includes -I./libft -03 -c 
CFLAGS = -Wall -Wextra -Werror
LIB = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft
CC = gcc
SRC_PATH = ./src/
SRC =	ft_draw_map.c \
		ft_init_map.c \
		ft_init_mlx.c \
		ft_key_press.c \
		ft_parse_file.c \
		ft_render_next_frame.c \
		ft_safe_exit.c \
		ft_safe_file.c \
		ft_valid_arg.c \
		main.c

OBJS = $(addprefix $(SRC_PATH),$(SRC))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

.c.o:
	$(CC) $(CFLAGS) $(OPTIONS) $(<) -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(OBJS)
	make -C ./libft fclean

re:	fclean all

.PHONY: re fclean clean all
