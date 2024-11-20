/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_mini_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:57:07 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:07 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	string_to_int(const char *str, int *result)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (0);
	*result = value * sign;
	return (1);
}

/**
 * Fonction qui permet de quitter le minishell.
 * peut etre utilisé avec un int d'erreur.
 * Free toutes les liste chainé et le tableau d'environnement.
 */
void	exe_exit(char *str, t_envp *envp, t_token *token)
{
	int	exit_code;
	int	conversion_success;

	exit_code = 0;
	while (*str == ' ')
		str++;
	if (*str == '\0')
	{
		free_token_list(token);
		return ;
	}
	conversion_success = string_to_int(str, &exit_code);
	if (!conversion_success || exit_code < 0 || exit_code > 255)
		exit_code = 1;
	free_token_list(token);
	free_t_envp(envp);
	exit(exit_code);
}
