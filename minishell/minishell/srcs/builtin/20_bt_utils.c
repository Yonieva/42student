/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_bt_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:57:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_word_count(char **cmd_list)
{
	int	i;

	i = 0;
	while (cmd_list[i])
		i++;
	return (i);
}

int	get_env_len(char *line)
{
	int	length;

	length = 0;
	while (line[length] == '_' || ft_isalpha(line[length]))
		length++;
	if (length == 0)
		return (0);
	while (line[length] == '_' || \
			ft_isalpha(line[length]) || ft_isdigit(line[length]))
		length++;
	return (length);
}

int	is_proper_env(char *env_name)
{
	int	full_len;
	int	env_len;

	full_len = ft_strlen(env_name);
	env_len = get_env_len(env_name);
	if (full_len == env_len)
		return (1);
	else
		return (0);
}

int	error_flag(t_envp *envp)
{
	envp->status_cmd = 1;
	return (1);
}

int	skip_spaces(const char *str, int index)
{
	while (str[index] == ' ')
		index++;
	return (index);
}
