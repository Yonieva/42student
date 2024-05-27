/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:23:28 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/21 15:10:03 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk_bonus.h"



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
	ft_printf("\033[0;33m|____/ \\___|_|    \\_/ \\___|_|       \n\n\n");
}


static void	ft_send_char(char c)
{
	static char	*str;
	char		*tmp;

	if (!str)
	{
		str = malloc(1);
		*str = '\0';
	}
	tmp = malloc(2);
	*tmp = c;
	*(tmp + 1) = '\0';
	str = ft_strjoin(str, tmp);
	if (c == 0)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
	free(tmp);
}


 
void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static int		c;
	static int		bit;
	static pid_t	client_pid;

	(void) context;
	if (!c || client_pid != sinfo->si_pid)
	{
		c = 255;
		bit = 0;
	}
	client_pid = sinfo->si_pid;
	if (sig == SIGUSR1)
		c ^= (128 >> bit);
	else if (sig == SIGUSR2)
		c |= (128 >> bit);
	if (++bit == 8)
	{
		ft_send_char(c);
		if (c == 0)
			kill(client_pid, SIGUSR2);
		bit = 0;
		c = 255;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}


int	main(void)
{
	int					pid;
	struct sigaction	sig;
	
	title_server();
	pid = getpid();
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	ft_printf("PID : %d\n", pid);
	ft_printf("Serveur en attente de signal ...\n");
	while (1)
		pause();
	return (EXIT_FAILURE);
}