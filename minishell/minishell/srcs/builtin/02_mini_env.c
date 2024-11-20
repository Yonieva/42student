/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_mini_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:36:52 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Fonction qui permet d'afficher l'environement du minishell (en fonction du 
 * SHLVL. ils n'ont pas tous le même).
 */
void	mini_env(t_envp *envp)
{
	int		i;
	char	*equal_sign;

	i = 0;
	while (envp->env[i])
	{
		if (get_env_value("PATH", envp->env) == NULL)
		{
			printf("minishell: env: No such file or directory\n");
			return ;
		}
		equal_sign = ft_strchr(envp->env[i], '=');
		if (equal_sign && equal_sign[1] != '\0')
			printf("%s\n", envp->env[i]);
		i++;
	}
	envp->status_cmd = 0;
}
