/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:58:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_tokens(const char *str, char delimiter)
{
	int	count;
	int	in_token;

	count = 0;
	in_token = 0;
	while (*str)
	{
		if (*str == delimiter)
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*allocate_token(const char *start, size_t len)
{
	char	*token;

	token = (char *)malloc(len + 1);
	if (token)
	{
		ft_strncpy(token, start, len);
		token[len] = '\0';
	}
	return (token);
}

char	*get_next_token(const char **str, char delimiter)
{
	const char	*start;
	char		*token;
	size_t		len;

	while (**str == delimiter)
		(*str)++;
	if (**str == '\0')
		return (NULL);
	start = *str;
	while (**str && **str != delimiter)
		(*str)++;
	len = *str - start;
	token = allocate_token(start, len);
	while (**str == delimiter)
		(*str)++;
	return (token);
}

void	free_split_command(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

char	**split_command(const char *cmd)
{
	char		**args;
	int			count;
	int			i;
	const char	*cmd_ptr;
	char		*token;

	count = count_tokens(cmd, ' ');
	args = (char **)malloc((count + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	cmd_ptr = cmd;
	i = 0;
	token = get_next_token(&cmd_ptr, ' ');
	while (token != NULL)
	{
		args[i] = token;
		if (!args[i++])
		{
			free_split_command(args);
			return (NULL);
		}
		token = get_next_token(&cmd_ptr, ' ');
	}
	args[i] = NULL;
	return (args);
}
