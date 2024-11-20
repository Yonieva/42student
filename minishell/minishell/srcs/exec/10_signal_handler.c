/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Global variable to store signal status
int	g_global_sig;

// Initializes a signal mask to block SIGINT and SIGQUIT
void	init_mask(struct sigaction *sig)
{
	sigemptyset(&sig->sa_mask);
	sigaddset(&sig->sa_mask, SIGINT);
	sigaddset(&sig->sa_mask, SIGQUIT);
}

// Configures signal handling for SIGINT and SIGQUIT
void	init_sigaction(struct sigaction *sig)
{
	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = &signal_handler;
	sigaction(SIGINT, sig, NULL);
	sig->sa_handler = SIG_IGN;
	sigaction(SIGQUIT, sig, NULL);
}

// Initializes the signal handling for SIGINT and SIGQUIT
void	init_signal(void)
{
	struct sigaction	sig;

	ft_memset(&sig, 0, sizeof(struct sigaction));
	init_mask(&sig);
	init_sigaction(&sig);
}

// Custom handler for SIGINT during command execution
void	handle_sigint_cmd(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		g_global_sig = 130;
	}
}

// Signal handler for the interactive shell (handles Ctrl+C)
void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_redisplay();
		g_global_sig = 130;
	}
}
