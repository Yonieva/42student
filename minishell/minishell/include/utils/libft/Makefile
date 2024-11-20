# Nom de la bibliothèque
NAME = libft.a

# Dossier des fichiers objets
OBJDIR = obj

# Fichiers source
SRCS =	ft_atoi.c\
	ft_itoa.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putnbr_fd.c\
	ft_putendl_fd.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strlen.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strjoin.c\
	ft_strchr.c\
	ft_strcpy.c\
	ft_strcat.c\
	ft_strncpy.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_substr.c\
	ft_calloc.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memcmp.c\
	ft_memset.c\
	ft_memmove.c\
	ft_bzero.c\
	ft_split.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_print_array.c\
	ft_dup.c\
	ft_dup2.c\
	ft_strcmp.c\
	ft_tablen.c\
	ft_strndup.c\
	ft_safe_malloc.c\
	ft_strspn.c\
	ft_strpbrk.c\
	ft_strtok.c\
	ft_realloc.c

# Fichiers objets
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Commandes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

# Règle par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJDIR)

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)

# Recompilation complète
re: fclean all
