# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 15:26:27 by yonieva           #+#    #+#              #
#    Updated: 2024/07/12 00:07:56 by yonieva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCFILES = ./code/main.c\
	./code/diner.c\
	./code/error.c\
	./code/init.c\
	./code/mutex_lock.c\
	./code/parsing.c\
	./code/synchro.c\
	./code/affichage.c\

OBJS = ${addprefix ./obj/, ${SRCFILES:.c=.o}}

DEP = ${OBJS:.o=.d}

CFLAGS = -Wall -Werror -Wextra -g

RS=        	 \033[0m
DARK=        \033[1;32m
RED=         \033[31m
GREEN=       \033[32m
YELLOW=      \033[33m
BLUE=        \033[34m
MAGENTA=     \033[35m
CYAN=        \033[36m
WHITE=       \033[37m
BOLDBLACK=   \033[1m\033[30m
BOLDRED=     \033[1m\033[31m
BOLDWHITE=   \033[1m\033[37m
BOLDGREEN=   \033[1m\033[32m

all : ${NAME} 

-include ${DEP}

./obj/%.o: ./%.c
	@mkdir -p ${@D}
	@cc ${CFLAGS} -MMD -MP -o $@ -c $<

${NAME}: ${OBJS}
	@echo "${YELLOW}Assemblage du client...${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${YELLOW}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}            
	@echo "${YELLOW}                       / _ \| |/ /                           ${RS}"              
	@echo "${YELLOW}                      | | | | ' /                            ${RS}"              
	@echo "${YELLOW}                      | |_| | . \                            ${RS}"              
	@echo "${YELLOW}                       \___/|_|\_\      					 ${RS}"
	@echo "\n"
	@echo "${GREEN}Projet Philosopher compilé avec succès.\n\n"

	
clean:
	@rm -rf obj/
	@rm -rf philo
	@echo "\n\n"
	@echo "${BOLDGREEN}Tous les objets ont été supprimés correctement.${RS}"
	@echo "${YELLOW}Retour au terminal.${RS}"
	@echo "\n\n"

fclean: clean
	@rm -f ${NAME}
	@rm -rf philo

re: fclean all

.PHONY: all clean fclean re