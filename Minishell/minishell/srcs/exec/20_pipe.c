/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:32 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Main function to execute a sequence of piped commands.
void	execute_pipes(t_token *token, t_envp *envp, t_signal *handler)
{
	t_process_data	args;
	pid_t			last_pid;
	int				pipefd[2];
	int				fd_in;

	fd_in = 0;
	args.envp = envp;
	args.handler = handler;
	while (token)
	{
		if (token->type == TOKEN_COMMAND)
		{
			args.token = token;
			create_pipe_if_needed(pipefd, token);
			setup_process_args(&args, fd_in, pipefd);
			handle_p(&args, &fd_in, pipefd, &last_pid);
		}
		token = token->next;
		if (token && token->type == TOKEN_PIPE)
			token = token->next;
	}
	wait_for_children();
}
