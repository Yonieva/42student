/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:07 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Function to handle heredoc input.
// Reads user input line by line and writes it to the pipe until the
// "delimiter" (end word) is reached.
void	handle_heredoc_input(int pipefd[2], char *delimiter)
{
	char	*line;

	signal(SIGINT, handle_sigint_heredoc);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_global_sig == 130)
				break ;
			write(1, "\n", 2);
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
	close(pipefd[1]);
}

// Sets up a pipe for handling heredoc, then calls handle_heredoc_input.
// It returns the read end of the pipe to allow for input redirection.
int	handle_heredoc(char *delimiter)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	handle_heredoc_input(pipefd, delimiter);
	close(pipefd[1]);
	return (pipefd[0]);
}

void	handle_sigint_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		close(STDIN_FILENO);
		g_global_sig = 130;
	}
}

void	reset_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
