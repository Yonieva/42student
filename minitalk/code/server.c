/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:23:28 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/02 19:26:12 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
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
	ft_printf("\033[0;33m|____/ \\___|_|    \\_/ \\___|_|       \n\n\n");
}

//-------------------------------------------------------------------------//
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	title_server();
	if (argc != 1)
	{
		ft_printf("\033[0;31mERROR !\n[0m");
		return (1);
	}
	pid = getpid();
	ft_printf("\033[0;33mPID : %d\n\n\n", pid);
	ft_printf("\033[0;33mServeur en attente de signaux d un client...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause ();
	}
	return (0);
}
