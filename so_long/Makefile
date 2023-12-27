NAME = so_long
SRC = so_long.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
MINILIBX_LINUX_DIR = minilibx_linux
LDFLAGS = -L//home/GITYO/so_long/minilibx -lmlx -lXext -lX11

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MINILIBX_LINUX_DIR)/libmlx.a
MLXFLAG = -L$(MINILIBX_LINUX_DIR) -lXext -lX11
INCLUDE = -I//home/GITYO/so_long -I$(MINILIBX_LINUX_DIR)


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MINILIBX_LINUX_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAG) $(LDFLAGS) $(MLX)


.c.o:
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_LINUX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_LINUX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re