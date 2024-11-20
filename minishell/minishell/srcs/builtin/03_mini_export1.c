/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_mini_export1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:37:02 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/**
 * Creates a new env entry in the format "var=value"
 */
char	*create_env_entry(const char *var, const char *value)
{
	int		var_len;
	int		value_len;
	char	*new_entry;

	var_len = ft_strlen(var);
	value_len = ft_strlen(value);
	new_entry = (char *)malloc(var_len + value_len + 2);
	if (!new_entry)
		return (NULL);
	ft_strcpy(new_entry, var);
	new_entry[var_len] = '=';
	ft_strcpy(new_entry + var_len + 1, value);
	return (new_entry);
}

/**
 * Returns the size of the env (number of entries)
 */
int	get_env_size(char **env)
{
	int	size;

	size = 0;
	while (env[size])
		size++;
	return (size);
}

/**
 * Allocates a new env array of size new_size and copies old_env into it
 */
char	**allocate_env_array(char **old_env, int old_size, int new_size)
{
	char	**new_env;
	int		i;

	new_env = malloc(new_size * sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_env[i] = old_env[i];
		i++;
	}
	return (new_env);
}

/**
 * Adds a new env variable to envp
 */
void	add_env_variable(t_envp *envp, char *new_entry)
{
	int		old_size;
	char	**new_env;

	old_size = get_env_size(envp->env);
	new_env = allocate_env_array(envp->env, old_size, old_size + 2);
	if (!new_env)
	{
		free(new_entry);
		return ;
	}
	free(envp->env);
	envp->env = new_env;
	envp->env[old_size] = new_entry;
	envp->env[old_size + 1] = NULL;
}

/**
 * Fonction export permet d'ajouter des variable d'environement 
 * ou bien de les modifiers.
 */
void	exe_export(t_envp *envp, char *args)
{
	char	*token;
	char	*saveptr;

	if (!args || ft_strcmp(args, "export") == 0)
	{
		print_sorted_env(envp->env);
		return ;
	}
	if (ft_strncmp(args, "export ", 7) == 0)
		args += 7;
	token = ft_strtok(args, " ", &saveptr);
	while (token != NULL)
	{
		process_export_token(envp, token);
		token = ft_strtok(NULL, " ", &saveptr);
	}
	envp->status_cmd = 0;
}
