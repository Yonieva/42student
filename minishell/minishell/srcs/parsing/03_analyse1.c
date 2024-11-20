/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_analyse1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Fonction de gestion des builtins
 * 1. Liste des builtins
 * 2. Vérification si c'est un buitin
 * 3. Ajout du Buitin_infos
 */
bool	is_builtin_command(char *com)
{
	return (!ft_strcmp(com, "cd") || !ft_strcmp(com, "echo")
		|| !ft_strcmp(com, "pwd") || !ft_strcmp(com, "env")
		|| !ft_strcmp(com, "export") || !ft_strcmp(com, "unset")
		|| !ft_strcmp(com, "exit"));
}

bool	check_builtin(char *value)
{
	char	*temp;
	int		i;
	int		len;
	bool	is_builtin;

	i = 0;
	len = 0;
	while (value[len] && value[len] != ' ')
		len++;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (false);
	while (i < len)
	{
		temp[i] = value[i];
		i++;
	}
	temp[i] = '\0';
	is_builtin = is_builtin_command(temp);
	free(temp);
	return (is_builtin);
}

char	*get_builtin_info(char *value)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (value[len] && value[len] != ' ')
		len++;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = value[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
