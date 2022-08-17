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
MLX = mlx
OPTIONS = -I/usr/include/ -Imlx_linux -Iincludes -I./libft -o3 -c -g3
CFLAGS = -Wall -Wextra -Werror
LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft
CC = gcc
SRC_PATH = ./src/
SRC =	ft_init_map.c \
		ft_init_mlx.c \
		ft_key_press.c \
		ft_parse_file.c \
		ft_render_next_frame.c \
		ft_safe_exit.c \
		ft_safe_file.c \
		ft_valid_arg.c \
		ft_draw_background.c \
		ft_calc_map.c \
		ft_draw_tile.c \
		ft_utils_mlx.c \
		main.c

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./mlx_linux

.c.o:
	$(CC) $(CFLAGS) $(OPTIONS) $(<) -o $(<:.c=.o)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make -C ./libft clean
	make -C ./mlx_linux clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./mlx_linux/libmlx_linux.a
	/bin/rm -f ./mlx_linux/libmlx.a
	make -C ./libft fclean

re:	fclean all

.PHONY: re fclean clean all $(LIBFT) $(MLX)
