/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:56 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/16 22:30:23 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk_bonus.h"

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
	ft_printf("\033[0;35m \\____|_|_|\\___|_| |_|\\__|      	    \n\n\n");
}
//------------------------------------------------------------------------//


static int		g_char_received;


static void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	(void) context;
	(void) sinfo;
	if (sig == SIGUSR1)
		g_char_received = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("\033[0;35mMessage recu et traite par le serveur ✅\n");
		exit(EXIT_SUCCESS);
	}
}

static void	ft_send_bit(char c, int bit, int pid)
{
	if (c & (128 >> bit))
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_printf("\033[0;35mL envoi du signal a echoue ❌\n");
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("\033[0;35mL envoi du signal a echoue ❌\n");
	}
}

static void	ft_char_to_binary(char c, int pid)
{
	int	bit;
	int	time_out;

	bit = 0;
	time_out = 0;
	while (bit < 8)
	{
		g_char_received = 0;
		ft_send_bit(c, bit, pid);
		while (!g_char_received)
		{
			if (time_out >= 3)
				ft_printf("\033[0;35mPas de reponse du serveur dans le delai 💀\n");
			time_out++;
			sleep(1);
		}
		time_out = 0;
		bit++;
		usleep(100);
	}
}


static void	ft_send_text(char *str, int len, int pid)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		ft_char_to_binary(str[i], pid);
		i++;
	}
}

/**
 * @brief The main program of the client.
 */
int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sact;
	
	title_client();
	if (argc != 3)
	{
		ft_printf("\033[0;35mErreur ! 3 arguments svp\n");
		return(1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{	
		ft_printf("\033[0;35mPID ERRONE\n");
		return(1);
	}
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	ft_send_text(argv[2], ft_strlen(argv[2]), pid);
	return (0);
}