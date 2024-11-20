/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Fonction de création de noeud pour la liste t_token.
 * 1. Noeud COMMAND
 * 2. Noeud PIPE
 * 3. Ajout du noeud a la chaine.
 */
t_token	*create_command_node(char *input)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->value = ft_strdup(input);
	new_node->type = TOKEN_COMMAND;
	new_node->is_builtin = check_builtin(input);
	new_node->builtin_info = get_builtin_info(input);
	new_node->is_last_command = false;
	new_node->file_in_out = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_token	*create_pipe_node(void)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->value = ft_strdup("|");
	new_node->type = TOKEN_PIPE;
	new_node->is_builtin = false;
	new_node->builtin_info = NULL;
	new_node->is_last_command = false;
	new_node->file_in_out = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_token_node(t_token **head, t_token *new_node)
{
	t_token	*current;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
