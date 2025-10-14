CC= cc
CFLAGS =
MLXFLAGS = -lmlx -lXext -lX11
NAME = cub3d
HFILES = cub3d.h
SRC = main.c utils.c errors.c exit.c ft_utils/str.c parser/parse.c map.c minimap.c
OBJ = ${SRC:.c=.o}

.PHONY: all re clean fclean

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