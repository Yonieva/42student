/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:09:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:09:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Waits for all child processes to finish execution.
void	wait_for_children(void)
{
	int	status;
	int	exit_status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			(void)exit_status;
		}
	}
}

// Creates a pipe if the current command is followed by another piped command.
void	create_pipe_if_needed(int *pipefd, t_token *token)
{
	if (token->next && token->next->type == TOKEN_PIPE)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
}

// Sets up input and output file descriptors for the process based on pipes.
void	setup_process_args(t_process_data *args, int fd_in, int *pipefd)
{
	args->in = fd_in;
	if (args->token->next && args->token->next->type == TOKEN_PIPE
		&& !args->token->file_in_out)
		args->out = pipefd[1];
	else
		args->out = STDOUT_FILENO;
}

// Executes a child process by setting up pipes, redirections, and exec the cmd.
void	execute_child_process(t_process_data *args, int *pipefd)
{
	if (args->in != STDIN_FILENO)
	{
		dup2(args->in, STDIN_FILENO);
		close(args->in);
	}
	if (args->out != STDOUT_FILENO)
	{
		dup2(args->out, STDOUT_FILENO);
		close(args->out);
	}
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (args->token->file_in_out)
		handle_redirections(args->token->file_in_out);
	if (builtin_check(args->token))
		builtin_selector(args->token, args->envp);
	else
		execute_execve(args->token, args->envp, args->handler);
	exit(EXIT_FAILURE);
}
