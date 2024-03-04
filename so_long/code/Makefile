# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 22:37:33 by khuynh            #+#    #+#              #
#    Updated: 2024/02/18 22:18:49 by yonieva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long

SLFILES = \
		maparse.c 	\
		mapcheck.c  \
		play.c 		\
		utils.c 	\
		xpm.c 		\
		free.c		\
		main.c

OBJS :=  	${addprefix ./obj/,${SLFILES:%.c=%.o}}
DEP   = 	${addprefix ./obj/,${OBJS:%.o=%.d}}



CFLAGS = -Wall -Werror -Wextra -MMD -MP -I./includes -g3
LIB	   = -L../lib/libft/ -lft -L ../lib/minilibx-linux -l mlx -lX11 -lXext



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



all: ${NAME}
-include ${DEP}

./obj/%.o: ./%.c
	@mkdir -p ${@D}
	@make -C ../lib/libft/
	@make -C ../lib/minilibx-linux
	@cc ${CFLAGS} -o $@ -c $<
	
${NAME} : ${OBJS}
	@echo "${MAGENTA}Assemblement...${RS}"
	@echo "${GREEN}Objs crees dans le repertoire${RS}"
	@echo "${MAGENTA}Compilation... ${RS}"
	@cc ${CFLAGS} -o ${NAME} ${OBJS} ${LIB}
	@echo "	 _____  ____  ____               _                _          _                "	
	@echo "|     !/    !/    |  ____________/ _______________/ _________/ ______ _________"	
	@echo "|     /_    /_    | /           ///              ///        ///     ! ---------"	
	@echo "|     ||    ||    |/     _______//_____     _____//      ___//_     |          "	
	@echo "|     ||    ||    ||     |_____       |     |    /   _,   \   |     |          "	
	@echo "|     ||    ||    ||     /____/       |     |   /          \  |     | ---------"	
	@echo "|     ||    ||    ||     |_________ _.|     |  /     __     \ |     |________ ."	
	@echo "|     ||    ||    ||              // ||     | /     /  \     \|             //|"	
	@echo "|_____||____||____||_____________//__!|_____!/_____/    \_____\____________//_!"	
	@echo "_______________ _/___________/ _/_________________/ _________/ _______________ "	
	@echo "-------------- //           ////                 ///        ///              /_"	
	@echo "              /     ________//_     _____________//      ___//_     _____     |"	
	@echo "              |     | ________|     |_____       /   _,   \   |     | __/     |"	
	@echo "------------- |     |/___    ||     /____/      /          \  |     |/     ___|"	
	@echo "_____________ |     |___/    ||     |_________ /     __     \ |     |\         "	
	@echo "------------- |              ||              //     /  \     \|     | \     \  "	
	@echo "_____________ |______________/|_____________//_____/    \_____\_____|__\     \ "	
	@echo "----------------------------------------------------------------------- \____/ "	
	@echo "${BOLDGREEN}By HIDEO KOJIMA ${RS}"	

clean:
	@rm -rf obj/
	@rm -f ${OBJS}
	@make $@ -C ../lib/libft/
	@echo "${BOLDGREEN}Tout les objs ont ete supprimes ${RS}"
	@echo "${BOLDGREEN}By HIDEO KOJIMA ${RS}"


fclean:
	@rm -rf obj/
	@rm -f ${NAME}
	@make $@ -C ../lib/libft/


re:	fclean all

.PHONY: all clean fclean re
