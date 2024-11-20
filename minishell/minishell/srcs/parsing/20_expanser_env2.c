/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_expanser_env2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_token_values(t_token *token, char **env, t_envp *envp)
{
	t_token	*current;
	char	*expanded_value;

	current = token;
	if (token->is_builtin == true)
	{
		while (current != NULL)
		{
			expanded_value = expand_variables_in_value(current->value,
					env, envp);
			free(current->value);
			current->value = expanded_value;
			current = current->next;
		}
	}
}

void	insert_string_into_result(t_exp_data *data, const char *str)
{
	while (*str)
	{
		data->result[data->j++] = *str++;
	}
}

void	is_single_quotes(const char *value, t_exp_data *data)
{
	data->in_single_quotes = !data->in_single_quotes;
	data->result[data->j++] = value[data->i++];
}

void	handle_variable_expansion(const char *value,
					t_exp_data *data, char **env, t_envp *envp)
{
	char	*pid_str;

	data->i++;
	if (value[data->i] == '$')
	{
		pid_str = ft_itoa(getpid());
		insert_string_into_result(data, pid_str);
		free(pid_str);
		data->i++;
	}
	else if (value[data->i] == '?')
	{
		if (g_global_sig == 130)
		{
			envp->status_cmd = 130;
			g_global_sig = 0;
		}
		pid_str = ft_itoa(envp->status_cmd);
		insert_string_into_result(data, pid_str);
		free(pid_str);
		data->i++;
	}
	else
		start_exp(value, data, env);
}
