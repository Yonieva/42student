/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_mini_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:55:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/10/11 20:19:12 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	should_copy_env_var(const char *env_var, const char *var, int var_len)
{
	return (!(ft_strncmp(env_var, var, var_len)
			== 0 && env_var[var_len] == '='));
}

void	fill_new_env(char **env, char **new_env,
	const char *var, int var_len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i])
	{
		if (should_copy_env_var(env[i], var, var_len))
			new_env[j++] = ft_strdup(env[i]);
		i++;
	}
	new_env[j] = NULL;
}

char	**copy_env_without_var(char **env, const char *var)
{
	int		i;
	int		count;
	int		var_len;
	char	**new_env;

	var_len = ft_strlen(var);
	count = 0;
	i = 0;
	while (env[i])
	{
		if (should_copy_env_var(env[i], var, var_len))
			count++;
		i++;
	}
	new_env = safe_malloc((count + 1) * sizeof(char *));
	fill_new_env(env, new_env, var, var_len);
	return (new_env);
}

void	exe_unset(t_envp *envp, char *args)
{
	char	**vars;
	char	**new_env;
	int		i;

	vars = ft_split(args, ' ');
	i = 0;
	while (vars[i])
	{
		new_env = copy_env_without_var(envp->env, vars[i]);
		if (new_env)
		{
			free_env(envp->env);
			envp->env = new_env;
		}
		i++;
	}
	i = 0;
	while (vars[i])
		free(vars[i++]);
	free(vars);
	envp->status_cmd = 0;
}

void	free_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}
