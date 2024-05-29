NAME = so_long
SRC = main.c so_long_core.c so_long_core2.c so_long_core3.c so_long_map1.c so_long_map2.c \
so_long_maputils.c so_long_maputils2.c so_long_utils.c get_next_line.c get_next_line_utils.c \
so_long_core4.c so_long_core5.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
LINKS = minilibx-linux/libmlx.a -lXext -lX11 -lm -lz


all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@rm $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
