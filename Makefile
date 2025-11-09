CC= cc
CFLAGS = -Wall -Wextra -Werror -w
MLXFLAGS = -lmlx -lXext -lX11
NAME = cub3D
SRC = main.c \
	$(wildcard adrs_tracker/*.c) \
	$(wildcard parser/*.c) \
	$(wildcard parser/parser_utils/*.c) \
	$(wildcard zengine/*.c)
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