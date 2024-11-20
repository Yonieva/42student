/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_analyse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:58 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Fonctions qui permettent la transformation des chaine de char
 * pour les passer au bon format :
 * 1. fermer les quotes si ce n'a pas été fait.
 * 2. retirer les espaces qui ne devrai pas etre present.
 */

void	check_quotes(const char *str, bool *s_q_open, bool *d_q_open)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			*s_q_open = !*s_q_open;
		else if (str[i] == '"')
			*d_q_open = !*d_q_open;
		i++;
	}
}

char	*close_quotes_if_needed(char *str)
{
	int		len;
	char	*new_str;
	bool	single_quote_open;
	bool	double_quote_open;

	single_quote_open = false;
	double_quote_open = false;
	check_quotes(str, &single_quote_open, &double_quote_open);
	len = ft_strlen(str);
	new_str = safe_malloc(len + 2);
	ft_strcpy(new_str, str);
	if (single_quote_open)
		new_str[len++] = '\'';
	else if (double_quote_open)
		new_str[len++] = '"';
	new_str[len] = '\0';
	return (new_str);
}

void	finalize_parsing(t_token *new_node, char **tokenarray)
{
	t_token	*current;

	current = new_node;
	while (current)
	{
		if (current != NULL && current->next == NULL)
			current->is_last_command = 1;
		current = current->next;
	}
	if (tokenarray != NULL)
		free_token_array(tokenarray);
}

int	check_onlyspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9)
			return (0);
		i++;
	}
	return (1);
}
