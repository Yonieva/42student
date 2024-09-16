
NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread

INCLUDES_DIR = includes

SRCS =	utils.c \
		parsing.c \
		init.c \
		simulation.c \
		main.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
