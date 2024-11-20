/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:00 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_redirection(char *arg)
{
	if (ft_strcmp(arg, "<<") == 0 || ft_strcmp(arg, "<") == 0
		|| ft_strcmp(arg, ">>") == 0 || ft_strcmp(arg, ">") == 0)
	{
		return (1);
	}
	return (0);
}

void	file_descriptor_handler(int in, int out)
{
	if (in != STDIN_FILENO)
	{
		if (dup2(in, STDIN_FILENO) < 0)
		{
			perror("dup2 error in file_descriptor_handler for stdin");
			exit(EXIT_FAILURE);
		}
		close(in);
	}
	if (out != STDOUT_FILENO)
	{
		if (dup2(out, STDOUT_FILENO) < 0)
		{
			perror("dup2 error in file_descriptor_handler for stdout");
			exit(EXIT_FAILURE);
		}
		close(out);
	}
}

void	handle_parent_process(pid_t pid, t_signal *handler)
{
	int	status;

	(void)handler;
	waitpid(pid, &status, WUNTRACED);
	if (WIFSIGNALED(status))
	{
		g_global_sig = WTERMSIG(status) + 128;
	}
	else if (WIFEXITED(status))
	{
		g_global_sig = WEXITSTATUS(status);
	}
}

void	handle_child_process(t_process_data *args)
{
	file_descriptor_handler(args->in, args->out);
	handle_redirections(args->token->file_in_out);
	execute_execve(args->token, args->envp, args->handler);
	exit(EXIT_FAILURE);
}

void	create_child_process(t_process_data *args)
{
	pid_t	pid;

	if (builtin_check(args->token))
		builtin_selector_chevron(args->token, args->envp);
	else
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			handle_child_process(args);
		else
			handle_parent_process(pid, args->handler);
	}
}
