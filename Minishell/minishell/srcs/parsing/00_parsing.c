/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:07:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*main_parsing(char *input, t_envp *env)
{
	char	**tokenarray;
	t_token	*token_list;

	token_list = NULL;
	tokenarray = ft_split_quoted(input);
	if (!tokenarray)
		return (NULL);
	if (!parse_tokens(tokenarray, &token_list))
	{
		free_token_list(token_list);
		free_token_array(tokenarray);
		return (NULL);
	}
	finalize_parsing(token_list, tokenarray);
	process_token_values(token_list, env->env, env);
	main_parse_string_chevron(token_list);
	return (token_list);
}

int	parse_tokens(char **tokenarray, t_token **token_list)
{
	int		i;

	i = 0;
	while (tokenarray[i])
	{
		if (!process_single_token(tokenarray[i], token_list))
			return (0);
		if (tokenarray[i + 1] && !add_pipe_to_list(token_list))
			return (0);
		i++;
	}
	return (1);
}

int	process_single_token(char *token, t_token **token_list)
{
	if (!process_token(token, token_list))
		return (0);
	return (1);
}

int	add_pipe_to_list(t_token **token_list)
{
	t_token	*pipe_node;

	pipe_node = create_pipe_node();
	if (!pipe_node)
		return (0);
	add_token_node(token_list, pipe_node);
	return (1);
}

int	process_token(char *token, t_token **token_list)
{
	char	*cleaned_value;
	char	*final_value;
	t_token	*new_node;

	cleaned_value = clean_whitespace(token);
	if (!cleaned_value)
		return (0);
	final_value = close_quotes_if_needed(cleaned_value);
	free(cleaned_value);
	if (!final_value)
		return (0);
	new_node = create_command_node(final_value);
	free(final_value);
	if (!new_node)
		return (0);
	add_token_node(token_list, new_node);
	return (1);
}
