/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_spliting_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:30 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_token(const char *str, int start, int len)
{
	return (ft_strndup(str + start, len));
}

int	handle_quote(char c, bool *in_quotes, char *quote_char)
{
	if ((c == '"' || c == '\'') && (!*in_quotes || *quote_char == c))
	{
		if (*in_quotes)
		{
			*in_quotes = 0;
			*quote_char = '\0';
		}
		else
		{
			*in_quotes = 1;
			*quote_char = c;
		}
	}
	return (*in_quotes);
}

char	**process_split(const char *str, char **result, int *count)
{
	int		i;
	int		start;
	bool	in_quotes;
	char	quote_char;

	i = 0;
	start = 0;
	in_quotes = false;
	quote_char = '\0';
	while (str[i])
	{
		handle_quote(str[i], &in_quotes, &quote_char);
		if ((str[i] == '|' && !is_pipe_in_q(str, i)) || str[i + 1] == '\0')
		{
			result[*count] = extract_token(str, start, i - start
					+ (str[i + 1] == '\0'));
			if (!result[(*count)++])
				return (free_tokens(result), NULL);
			start = i + 1;
		}
		i++;
	}
	return (result);
}

char	**ft_split_quoted(const char *str)
{
	char	**result;
	int		count;

	count = 0;
	result = safe_malloc(sizeof(char *) * (strlen(str) / 2 + 2));
	if (!result)
		return (NULL);
	if (!process_split(str, result, &count))
		return (NULL);
	result[count] = NULL;
	return (result);
}

bool	is_pipe_in_q(const char *input, int index)
{
	bool	iq;
	char	qchar;
	int		i;

	iq = false;
	qchar = '\0';
	i = 0;
	while (i < index)
	{
		if ((input[i] == '"' || input[i] == '\'') && (!iq || qchar == input[i]))
		{
			if (iq)
			{
				iq = false;
				qchar = '\0';
			}
			else
			{
				iq = true;
				qchar = input[i];
			}
		}
		i++;
	}
	return (iq);
}
