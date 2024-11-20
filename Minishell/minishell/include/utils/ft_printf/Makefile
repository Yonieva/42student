# Nom de la bibliothèque
NAME = libftprintf.a

# Dossier des fichiers objets
OBJDIR = obj
SRCDIR = SRCS

# Fichiers source
SRCS = $(SRCDIR)/ft_printf.c\
	$(SRCDIR)/ft_transform.c\
	$(SRCDIR)/ft_write.c\
	$(SRCDIR)/ft_format.c\
	$(SRCDIR)/ft_puthex.c\
	$(SRCDIR)/ft_compteur.c

# Fichiers objets
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Commandes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes

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
