NAME = libft.a
CFLAG = -Wall -Wextra -Werror
OPTION = -I./ -c
SRC_PATH = ./
SRC =	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRC_GNL = get_next_line.c get_next_line_utils.c
SRC_PATH_GNL = ./gnl/

SRC_PRINTF =	ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putnbr_unsigned.c \
		ft_putptr.c \
		ft_putstr.c
SRC_PATH_PRINTF = ./printf/src/

SRCS =	$(addprefix $(SRC_PATH),$(SRC)) \
	$(addprefix $(SRC_PATH_GNL),$(SRC_GNL)) \
	$(addprefix $(SRC_PATH_PRINTF),$(SRC_PRINTF))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	gcc $(CFLAG) $(OPTION) $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

