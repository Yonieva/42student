/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:39:22 by acabarba          #+#    #+#             */
/*   Updated: 2024/10/11 20:22:07 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_signal	handler;
	t_envp		*envp;

	if (ac != 1)
		exit(EXIT_FAILURE);
	(void)av;
	envp = NULL;
	init_signal();
	init_minishell(&envp, env);
	main_loop(envp, &handler);
	cleanup_and_exit(envp);
	return (0);
}

void	init_minishell(t_envp **envp, char **env)
{
	*envp = (t_envp *)malloc(sizeof(t_envp));
	if (*envp == NULL)
		exit(EXIT_FAILURE);
	(*envp)->env = env_dup(env).env;
	init_terminal(*envp);
}

void	main_loop(t_envp *envp, t_signal *handler)
{
	char		*input;
	t_token		*token_list;

	while (1)
	{
		setup_signal_handling();
		input = readline("minishell> ");
		if (input == NULL)
		{
			write(1, "exit\n", 5);
			cleanup_and_exit(envp);
		}
		if (*input && !check_onlyspace(input))
		{
			add_history(input);
			token_list = main_parsing(input, envp);
			signal(SIGINT, handle_sigint_cmd);
			free(input);
			main_exec(token_list, envp, handler);
			free_token_list(token_list);
		}
		else
			free(input);
	}
}

void	cleanup_and_exit(t_envp *envp)
{
	clear_history();
	free_t_envp(envp);
	exit(0);
}
