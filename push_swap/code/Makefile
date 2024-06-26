# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 15:57:41 by yonieva           #+#    #+#              #
#    Updated: 2024/05/27 16:51:50 by yonieva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCFILES = sort_stack.c\
	main.c\
	a_to_b.c\
	b_to_a.c\
	command_push.c\
	command_rev_rotate.c\
	command_rotate.c\
	command_sort.c\
	command_swap.c\
	free_error.c\
	stack_init.c\
	stack_tools.c

OBJS = ${addprefix ./obj/, ${SRCFILES:.c=.o}}

DEP = ${OBJS:.o=.d}

CFLAGS = -Wall -Werror -Wextra -g
LIB	   = -L../lib/libft/ -lft

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
	@make -C ../lib/libft/
	@cc ${CFLAGS} -MMD -MP -o $@ -c $<

${NAME}: ${OBJS}
	@echo "${YELLOW}Assemblage du client...${RS}"
	@echo "${GREEN}Objets créés dans le répertoire${RS}"
	@echo "${YELLOW}Compilation...${RS}"
	@cc ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@echo "${YELLOW}  ____ ___  __  __ ____ ___ _        _  _____ ___ ___  _   _ ${RS}"               
	@echo "${YELLOW} / ___/ _ \|  \/  |  _ \_ _| |      / \|_   _|_ _/ _ \| \ | |${RS}"             
	@echo "${YELLOW}| |  | | | | |\/| | |_\ | || |     / _ \ | |  | | | | |  \| |${RS}"              
	@echo "${YELLOW}| |__| |_| | |  | |  __/| || |___ / ___ \| |  | | |_| | |\  |${RS}"              
	@echo "${YELLOW} \____\___/|_|  |_|_|  |___|_____/_/   \_\_| |___\___/|_| \_|${RS}"             
	@echo "${YELLOW}                       / _ \| |/ /                           ${RS}"              
	@echo "${YELLOW}                      | | | | ' /                            ${RS}"              
	@echo "${YELLOW}                      | |_| | . \                            ${RS}"              
	@echo "${YELLOW}                       \___/|_|\_\        					 													${RS}"
	@echo "\n\n"
	@echo "${GREEN}Push_Swap compilé avec succès.\n\n"

	
clean:
	@rm -rf obj/
	@make clean -C ../lib/libft/
	@echo "\n\n"
	@echo "${BOLDGREEN}Tous les objets ont été supprimés correctement.${RS}"
	@echo "${YELLOW}Retour au terminal.${RS}"
	@echo "\n\n"

fclean: clean
	@rm -f ${NAME}
	@make fclean -C ../lib/libft/

re: fclean all

.PHONY: all clean fclean re

