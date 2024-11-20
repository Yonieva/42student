/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:01:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Fonction utilitaire de la gestion du parsing
 * 1. Affichage de la liste.
 * 2. Free de la liste.
 * 3. Free du tableau de tableau
 */
void	print_token_list(t_token *head)
{
	t_token	*current;
	char	*is_builtin_str;
	int		i;

	i = 1;
	current = head;
	while (current != NULL)
	{
		if (current->is_builtin)
			is_builtin_str = "Yes";
		else
			is_builtin_str = "No";
		printf("\nt_token node n° %d\nValue: %s\nType: %d\nIs Builtin: %s\n"
			"Builtin Info: %s\nIs Last Command: %d\n", i, current->value,
			current->type, is_builtin_str, current->builtin_info,
			current->is_last_command);
		print_chevron_node(current);
		printf("---------------------------------------------\n");
		i++;
		current = current->next;
	}
}

/**
 * Fonction qui free la liste t_token ainsi que tous les elements qui
 * la compose a savoir, t_chevron et toutes les infos de token.
 */
void	free_token_list(t_token *token_list)
{
	t_token	*temp;

	while (token_list != NULL)
	{
		temp = token_list;
		token_list = token_list->next;
		if (temp->file_in_out)
			free_chevron_list(temp->file_in_out);
		if (temp->value)
			free(temp->value);
		if (temp->builtin_info)
			free(temp->builtin_info);
		free(temp);
	}
}

/**
 * Permet de free le tableau de token qui est utilisé pour
 * créer la liste chainé de token.
 */
void	free_token_array(char **tokenarray)
{
	int	i;

	i = 0;
	if (!tokenarray)
		return ;
	while (tokenarray[i] != NULL)
	{
		free(tokenarray[i]);
		i++;
	}
	free(tokenarray);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

/**
 * Fonction qui permet de free la liste chainé t_chevron si elle existe
 */
void	free_chevron_list(t_chevron *chevron_list)
{
	t_chevron	*temp;

	while (chevron_list != NULL)
	{
		temp = chevron_list;
		chevron_list = chevron_list->next;
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
