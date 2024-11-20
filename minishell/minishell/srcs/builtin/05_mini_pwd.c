/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_mini_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:57:01 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * permet de recuperer le path 
 * sans passer par l'env car utilisation de la fonction 'getcwd'
 */
int	exe_pwd(t_envp *envp)
{
	char	temp[1024];

	if (getcwd(temp, sizeof(temp)) == NULL)
		return (error_flag(envp), 1);
	printf("%s\n", temp);
	envp->status_cmd = 0;
	return (0);
}
