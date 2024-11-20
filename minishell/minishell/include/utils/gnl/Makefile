# Nom de la bibliothèque
NAME = libgnl.a

# Dossier des fichiers objets
OBJDIR = obj
SRCDIR = .

# Fichiers source
SRCS = $(SRCDIR)/get_next_line.c \
	   $(SRCDIR)/get_next_line_utils.c

# Fichiers objets
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Commandes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I.

# Règle par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des fichiers objets
clean: 
	@$(RM) $(OBJDIR)

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)

# Recompilation complète
re: fclean all
