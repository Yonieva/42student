/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_mini_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:37:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_env_var(t_envp *envp, const char *var, const char *value)
{
	int		var_len;
	char	*new_entry;
	int		i;

	i = 0;
	var_len = ft_strlen(var);
	if (value == NULL)
		new_entry = ft_strdup(var);
	else
		new_entry = create_env_entry(var, value);
	if (!new_entry)
		return ;
	while (envp->env[i])
	{
		if (ft_strncmp(envp->env[i], var, var_len) == 0
			&& (envp->env[i][var_len] == '=' || envp->env[i][var_len] == '\0'))
		{
			free(envp->env[i]);
			envp->env[i] = new_entry;
			return ;
		}
		i++;
	}
	add_env_variable(envp, new_entry);
}

void	update_env(t_envp *envp, const char *var, int var_len, char *new_entry)
{
	int	i;

	i = 0;
	while (envp->env[i])
	{
		if (ft_strncmp(envp->env[i], var, var_len) == 0
			&& envp->env[i][var_len] == '=')
		{
			free(envp->env[i]);
			envp->env[i] = new_entry;
			return ;
		}
		i++;
	}
	add_env_variable(envp, new_entry);
}

int	is_var_in_env(t_envp *envp, const char *var)
{
	int		i;
	size_t	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while (envp->env[i])
	{
		if (ft_strncmp(envp->env[i], var, var_len) == 0
			&& envp->env[i][var_len] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	process_export_token(t_envp *envp, char *token)
{
	char	*equal_sign;
	char	*var;

	equal_sign = ft_strchr(token, '=');
	if (equal_sign)
	{
		var = ft_strndup(token, equal_sign - token);
		if (var && *var)
		{
			if (ft_strcmp(var, "_") != 0)
				set_env_var(envp, var, equal_sign + 1);
		}
		free(var);
	}
	else
	{
		if (ft_strcmp(token, "_") != 0 && !is_var_in_env(envp, token))
			set_env_var(envp, token, NULL);
	}
}
