/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_pathing_gestion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:46:07 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/25 18:01:54 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *  Fonction pour concaténer deux chaînes avec un "/" entre elles
 */
char	*join_path(const char *path, const char *cmd)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(path) + ft_strlen(cmd) + 2;
	full_path = (char *)malloc(len);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	return (full_path);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

/**
 *  Fonction pour récupérer le chemin absolu d'une commande
 */
char	*try_access_command(char **paths, const char *cmd)
{
	char	*command_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		command_path = join_path(paths[i], cmd);
		if (command_path && access(command_path, X_OK) == 0)
		{
			free_paths(paths);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

char	*get_command_path(const char *cmd, t_envp *envp)
{
	char	*path_env;
	char	**paths;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_env = ft_getenv(envp, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (try_access_command(paths, cmd));
}

char	*ft_getenv(t_envp *envp, const char *path)
{
	int		i;
	int		len;

	if (!envp || !envp->env || !path)
		return (NULL);
	len = ft_strlen(path);
	i = 0;
	while (envp->env[i])
	{
		if (ft_strncmp(envp->env[i], path, len) == 0
			&& envp->env[i][len] == '=')
		{
			return (envp->env[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
