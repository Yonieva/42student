/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:58:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Affichage de l'environement
 */
void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

char	*get_env_value(char *str, char **env)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len) == 0 && env[i][len] == '=')
			return (ft_strdup(env[i] + len + 1));
		i++;
	}
	return (NULL);
}

void	set_env_value(char **env, char *key, char *new_value)
{
	int		i;
	char	*temp;
	int		key_len;

	i = 0;
	if (!env || !key || !new_value)
		return ;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=')
		{
			free(env[i]);
			temp = safe_malloc(ft_strlen(key) + ft_strlen(new_value) + 2);
			ft_strcpy(temp, key);
			ft_strcat(temp, "=");
			ft_strcat(temp, new_value);
			env[i] = temp;
			return ;
		}
		i++;
	}
	return ;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_t_envp(t_envp *envp)
{
	int	i;

	if (envp == NULL)
		return ;
	if (envp->env)
	{
		i = 0;
		while (envp->env[i] != NULL)
		{
			free(envp->env[i]);
			i++;
		}
		free(envp->env);
	}
	free(envp);
}
