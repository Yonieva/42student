/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31_parse_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:02:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_chevron	*parse_string_chevron(char *str)
{
	t_chevron	*head;
	t_chevron	*last_command_node;
	char		*current_position;

	head = NULL;
	last_command_node = NULL;
	current_position = str;
	while (*current_position)
	{
		parse_chevron_token(&current_position, &head, &last_command_node);
		if (*current_position == '\0')
			break ;
	}
	return (head);
}

void	parse_chevron_token(char **current_position, t_chevron **head,
			t_chevron **last_command_node)
{
	char			*tokens[4];
	t_chevron_type	types[4];
	t_chevron_data	data;

	initialize_tokens_types(tokens, types);
	data.current_position = current_position;
	data.head = head;
	data.last_command_node = last_command_node;
	data.chevron = NULL;
	data.token_length = 0;
	data.token_index = -1;
	data.types = types;
	find_chevron_in_str(*current_position, tokens, &data);
	if (data.chevron)
	{
		parse_before_chevron(&data);
		parse_after_chevron(&data);
	}
	else
		*current_position += 1;
}

void	initialize_tokens_types(char **tokens, t_chevron_type *types)
{
	tokens[0] = ">>";
	tokens[1] = "<<";
	tokens[2] = ">";
	tokens[3] = "<";
	types[0] = DOUBLE_OUT;
	types[1] = DOUBLE_IN;
	types[2] = OUT;
	types[3] = IN;
}
