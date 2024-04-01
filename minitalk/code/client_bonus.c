/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:56 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/01 23:35:39 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib/minitalk_bonus.h"

int end = 0;


void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1); 
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void signal_recu_du_server(int signum) 
{
	if (signum == SIGUSR1 && end == 0)
	{
		ft_printf("Message recu et traite par le serveur\n");
		end = 1;
	}
   
}


void	title_client(void)
{
		ft_printf("\033[0;35m __  __ _       _ _        _ _       \n");                                
		ft_printf("\033[0;35m|  \\/   _ _ __  _  |_ __ _| | | __   \n");                         
		ft_printf("\033[0;35m| |\\/| | | '_ \\| | __/ _` | | |/ /   \n");                         
		ft_printf("\033[0;35m| |  | | | | | | | || \\_| | |   <    \n");                            
		ft_printf("\033[0;35m|_|__|_|_|_| |_|_|\\__\\__,_|_|_|\\_\\   \n");                            
		ft_printf("\033[0;35m / ___|  _  ___ _ __ | |_            \n");                              
		ft_printf("\033[0;35m| |   | | |/ _ \\ '_ \\| __|           \n");                             
		ft_printf("\033[0;35m| |___| | |  __/ | | | |_            \n");                              
		ft_printf("\033[0;35m \\____|_|_|\\___|_| |_|\\__|      	    \n\n\n\n");                
}


//---------------------------------------------------------------------------------//
int	main(int argc, char **argv)
{

	title_client();
	
	int	pid_server;
	int	i = 0;
	;

	if (argc == 3)
	{
	
		pid_server = ft_atoi(argv[1]);
		signal(SIGUSR1, signal_recu_du_server);
		while (argv[2][i] != '\0')
		{
			ft_atob(pid_server, argv[2][i]);
			i++;
		}
		ft_atob(pid_server, '\n');
		usleep(500);
		
	}
	else
	{
		ft_printf("\033[0;31mERROR !\n\n\n");
		return (1);
	}	
	return (0);
}