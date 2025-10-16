CC= cc
CFLAGS = -Wall -Wextra -Werror -w
MLXFLAGS = -lmlx -lXext -lX11
NAME = cub3d
SRC = main.c \
	$(wildcard parser_utils/*.c) \
	$(wildcard parser/*.c) \
	$(wildcard raycaster/*.c)
OBJ = ${SRC:.c=.o}


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all re clean fclean