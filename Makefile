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
CFLAGS =
SRCS_OBJS = objs/
SRC_PATH = src/
SRC_INCLUDE = includes/

UNAME = $(shell uname -s)

ifeq ($(UNAME),Linux)
	LIB = -lm -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	SRC_MLX = ./mlx_linux
	OPTIONS = -Imlx_linux
endif
ifeq ($(UNAME),Darwin)
	LIB = -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
	SRC_MLX = ./mlx_macos
	OPTIONS = -Imlx_macos
endif

OPTIONS += -I/usr/include/ -Iincludes -I./libft -o3 -c
LIB += -L./libft -lft
CC = gcc

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
		ft_math_utils.c \
		ft_draw_menu.c \
		ft_atoi_hex.c \
		main.c
HEADER = fdf.h

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(SRCS_OBJS),$(OBJ))
HEADERS = $(addprefix $(SRC_INCLUDE),$(HEADER))

all:$(NAME)

$(LIBFT):
	make -C $(LIBFT)

$(MLX):
	make -C ${SRC_MLX}
	cp ${SRC_MLX}/libmlx.dylib ./

$(SRCS_OBJS)%.o: $(SRC_PATH)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(OPTIONS) $(<) -o $(@) -g3 -fsanitize=address

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME) -g3 -fsanitize=address

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean
	make -C $(SRC_MLX) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re:	fclean all

.PHONY: re fclean clean all $(LIBFT) $(MLX)
