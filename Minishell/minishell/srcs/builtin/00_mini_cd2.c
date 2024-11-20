/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_mini_cd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:00:34 by kpourcel          #+#    #+#             */
/*   Updated: 2024/09/26 17:01:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_new_pwd_error(char *home_path, t_envp *envp)
{
	if (home_path)
		free(home_path);
	error_flag(envp);
	return (1);
}
