/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:23:28 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/01 23:36:00 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk_bonus.h"


void	ft_btoa(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;
	(void)context;
	(void)info;
	
	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR1);
	}
	
	
}



void	title_server(void)
{
		ft_printf("\033[0;33m __  __ _       _ _        _ _         \n");                
		ft_printf("\033[0;33m|  \\/  (_)_ __ (_) |_ __ _| | | __    \n");              
		ft_printf("\033[0;33m| |\\/| | | '_ \\| | __/ _` | | |/ /   \n");               
		ft_printf("\033[0;33m| |  | | | | | | | || (_| | |   <      \n");                
		ft_printf("\033[0;33m|_|__|_|_|_| |_|_|\\__\\__,_|_|_|\\_\\ \n");                
		ft_printf("\033[0;33m/ ___|  ___ _ ____   _____ _ __        \n");                
		ft_printf("\033[0;33m\\___ \\ / _ \\ '__\\ \\ / / _ \\ '__| \n");                
		ft_printf("\033[0;33m ___) |  __/ |   \\ V /  __/ |         \n");                
		ft_printf("\033[0;33m|____/ \\___|_|    \\_/ \\___|_|       \n\n\n\n");	
}





//---------------------------------------------------------------------------------//
int	main(int argc, char **argv)
{

	title_server();

	int	pid = getpid();
	struct sigaction	sigact;
	
	sigact.sa_sigaction = ft_btoa;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);

	
	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[0;31mERROR !\n[0m");
		return (1);
	}
	
	ft_printf("\033[0;33mPID : %d\n\n\n", pid);
	ft_printf("\033[0;33mServeur en attente de signaux d un client...\n");
	
	while (1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		pause ();
	}
	return (0);
}