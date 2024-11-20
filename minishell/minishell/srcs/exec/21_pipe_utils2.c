/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_pipe_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Processes heredoc redirection for the command if applicable.
void	process_heredoc_redirection(t_process_data *args, int *fd_in)
{
	int	heredoc_fd;

	if (args->token->file_in_out && args->token->file_in_out->type == DOUBLE_IN)
	{
		heredoc_fd = handle_heredoc(args->token->file_in_out->value);
		if (heredoc_fd != -1)
			*fd_in = heredoc_fd;
	}
}

// Sets up the fds for the child process, including pipes and redirections.
void	setup_child_execution(int *fd_in, int *pipefd, t_process_data *args)
{
	if (*fd_in != STDIN_FILENO)
	{
		dup2(*fd_in, STDIN_FILENO);
		close(*fd_in);
	}
	if (pipefd[1] != STDOUT_FILENO)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (args->token->file_in_out && args->token->file_in_out->type != DOUBLE_IN)
		handle_redirections(args->token->file_in_out);
	if (builtin_check(args->token))
		builtin_selector(args->token, args->envp);
	else
		execute_execve(args->token, args->envp, args->handler);
}

// Manages the parent process actions after forking the child,
// closing necessary file descriptors.
void	process_parent_actions(int *fd_in, int *pipefd, pid_t pid,
	pid_t *last_pid)
{
	if (*fd_in != 0)
		close(*fd_in);
	if (pipefd[1] != -1)
		close(pipefd[1]);
	*fd_in = pipefd[0];
	*last_pid = pid;
}

// Forks a process and handles child/parent process roles.
void	handle_p(t_process_data *args, int *fd_in, int *pipefd, pid_t *last_pid)
{
	pid_t	pid;

	process_heredoc_redirection(args, fd_in);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		setup_child_execution(fd_in, pipefd, args);
		exit(EXIT_FAILURE);
	}
	else
	{
		process_parent_actions(fd_in, pipefd, pid, last_pid);
	}
}

// Forks a new process and executes a cmd, restoring default signal handling
pid_t	fork_and_execute(char *cmd_path, char **split_args, t_envp *envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTERM, SIG_DFL);
		execve_error_handling(cmd_path, split_args, envp);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
