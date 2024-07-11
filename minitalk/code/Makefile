# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 22:22:02 by yonieva           #+#    #+#              #
#    Updated: 2024/07/12 01:24:49 by yonieva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLT = client
NAMESERV = server

NAMECLTBONUS = client_bonus
NAMESERVBONUS = server_bonus

SRCFILES_CLIENT = client.c
SRCFILES_SERVER = server.c

SRCFILES_CLIENT_BONUS = client_bonus.c
SRCFILES_SERVER_BONUS = server_bonus.c


OBJS_CLIENT = ${addprefix ./obj/, ${SRCFILES_CLIENT:.c=.o}}
OBJS_SERVER = ${addprefix ./obj/, ${SRCFILES_SERVER:.c=.o}}

OBJS_CLIENT_BONUS = ${addprefix ./obj/, ${SRCFILES_CLIENT_BONUS:.c=.o}}
OBJS_SERVER_BONUS = ${addprefix ./obj/, ${SRCFILES_SERVER_BONUS:.c=.o}}

DEP_CLIENT = ${OBJS_CLIENT:.o=.d}
DEP_SERVER = ${OBJS_SERVER:.o=.d}

DEP_CLIENT_BONUS = ${OBJS_CLIENT_BONUS:.o=.d}
DEP_SERVER_BONUS = ${OBJS_SERVER_BONUS:.o=.d}

CFLAGS = -Wall -Werror -Wextra 
LIB	   = -L../lib/libft/ -lft

RS=        \033[0m
DARK=        \033[1;32m
RED=        \033[31m
GREEN=        \033[32m
YELLOW=        \033[33m
BLUE=        \033[34m
MAGENTA=    \033[35m
CYAN=        \033[36m
WHITE=        \033[37m
BOLDBLACK=    \033[1m\033[30m
BOLDRED=    \033[1m\033[31m
BOLDWHITE=    \033[1m\033[37m
BOLDGREEN=    \033[1m\033[32m

all: ${NAMECLT} ${NAMESERV} ${NAMECLTBONUS} ${NAMESERVBONUS}

-include ${DEP_CLIENT} ${DEP_SERVER} ${DEP_CLIENT_BONUS} ${DEP_SERVER_BONUS}

./obj/%.o: ./%.c
	@mkdir -p ${@D}
	@make -C ../lib/libft/
	@cc ${CFLAGS} -MMD -MP -o $@ -c $<

${NAMECLT}: ${OBJS_CLIENT}
	@echo "${MAGENTA}Assemblage du client...\n${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${MAGENTA}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS_CLIENT} ${LIB} -o ${NAMECLT}
	@echo "Client compilé avec succès.\n\n"

${NAMECLTBONUS}: ${OBJS_CLIENT_BONUS}
	@echo "${MAGENTA}Assemblage du client bonus...\n${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${MAGENTA}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS_CLIENT_BONUS} ${LIB} -o ${NAMECLTBONUS}
	@echo "Client bonus compilé avec succès.\n\n"


${NAMESERVBONUS}: ${OBJS_SERVER_BONUS}
	@echo "${MAGENTA}Assemblage du serveur bonus...\n${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${MAGENTA}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS_SERVER_BONUS} ${LIB} -o ${NAMESERVBONUS}
	@echo "Serveur bonus compilé avec succès.\n\n"
	
${NAMESERV}: ${OBJS_SERVER}
	@echo "${MAGENTA}Assemblage du serveur...\n${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${MAGENTA}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS_SERVER} ${LIB} -o ${NAMESERV}
	@echo " __  __ ___ _   _ ___ _____  _    _     _  __"  
	@echo "|  \/  |_ _| \ | |_ _|_   _|/ \  | |   | |/ /" 
	@echo "| |\/| || ||  \| || |  | | / _ \ | |   | ' / " 
	@echo "| |  | || || |\  || |  | |/ ___ \| |___| . \ "  
	@echo "Serveur compilé avec succès.\n\n"

clean:
	@rm -rf obj/
	@make clean -C ../lib/libft/
	@echo "${BOLDGREEN}Tous les objets ont été supprimés.${RS}"

fclean: clean
	@rm -f ${NAMECLT} ${NAMESERV} ${NAMECLTBONUS} ${NAMESERVBONUS}
	@make fclean -C ../lib/libft/

re: fclean all

.PHONY: all clean fclean re

