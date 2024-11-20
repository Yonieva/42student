/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31_parse_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:30:29 by acabarba          #+#    #+#             */
/*   Updated: 2024/08/16 14:55:6 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_chevron	*create_chevron(t_chevron_type type, const char *value)
{
	t_chevron	*chevron;

	chevron = (t_chevron *)malloc(sizeof(t_chevron));
	chevron->type = type;
	chevron->value = strdup(value);
	chevron->next = NULL;
	return (chevron);
}

void	append_chevron(t_chevron **head, t_chevron_type type, const char *value)
{
	t_chevron	*new_chevron;
	t_chevron	*current;

	new_chevron = create_chevron(type, value);
	if (*head == NULL)
		*head = new_chevron;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_chevron;
	}
}

void	print_chevron_list(t_chevron *head)
{
	t_chevron	*current;

	current = head;
	while (current != NULL)
	{
		printf("Type: %d, Value: %s\n", current->type, current->value);
		current = current->next;
	}
}

void	main_parse_string_chevron(t_token *token)
{
	t_token	*current;

	current = token;
	while (current)
	{
		if (current->type == TOKEN_COMMAND)
			if (contains_chevrons(current->value))
				current->file_in_out = parse_string_chevron(current->value);
		current = current->next;
	}
}
