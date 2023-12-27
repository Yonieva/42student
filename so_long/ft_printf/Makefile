NAME = libftprintf.a

SRC = ft_printf.c add_ft.c
OBJ = $(SRC:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
		 ar rcs $(NAME) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
