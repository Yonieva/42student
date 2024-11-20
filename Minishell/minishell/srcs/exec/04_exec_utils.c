/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:08 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**free_token(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	count_token(t_token *token)
{
	int		count;
	t_token	*current;

	count = 0;
	current = token;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	count_tokens_before_pipe(t_token *token)
{
	int		count;
	t_token	*current;

	count = 0;
	current = token;
	while (current && current->type != TOKEN_PIPE)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	**allocate_and_fill_tokens(t_token *token, int count)
{
	char		**str;
	int			i;
	t_token		*current;

	i = 0;
	str = (char **)safe_malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	current = token;
	while (current && current->type != TOKEN_PIPE)
	{
		str[i] = ft_strdup(current->value);
		if (!str[i])
		{
			free_token(str, i);
			return (NULL);
		}
		i++;
		current = current->next;
	}
	str[i] = NULL;
	return (str);
}

char	**convert_token(t_token *token)
{
	int		count;
	char	**str;

	count = count_tokens_before_pipe(token);
	str = allocate_and_fill_tokens(token, count);
	return (str);
}
