/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32_parse_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:02:41 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Initialisation de la structure t_chevron dans le noeud de la liste token si 
 * il y a des chevrons
 */
void	find_chevron_in_str(char *current_position, char **tokens,
								t_chevron_data *data)
{
	int		i;
	char	*found;

	i = 0;
	while (i < 4)
	{
		if (tokens[i] == NULL)
		{
			i++;
			continue ;
		}
		found = strstr(current_position, tokens[i]);
		if (found && (data->chevron == NULL || found < data->chevron))
		{
			data->chevron = found;
			data->token_length = strlen(tokens[i]);
			data->token_index = i;
		}
		i++;
	}
}

void	parse_before_chevron(t_chevron_data *data)
{
	char	*command_part;

	if (*(data->current_position) != data->chevron)
	{
		command_part = strndup(*(data->current_position), data->chevron
				- *(data->current_position));
		if (*(data->last_command_node) == NULL && *command_part != '\0')
		{
			append_chevron(data->head, COMMAND, command_part);
			*(data->last_command_node) = *(data->head);
		}
		free(command_part);
	}
	*(data->current_position) = data->chevron;
}

void	parse_after_chevron(t_chevron_data *data)
{
	char	*end_of_value;
	char	*value_part;
	char	*current_position;
	size_t	length;
	size_t	value_length;

	if (data->chevron == NULL || data->token_length <= 0)
		return ;
	*(data->current_position) = data->chevron + data->token_length;
	while (**(data->current_position) == ' ')
		(*(data->current_position))++;
	end_of_value = ft_strchr(*(data->current_position), ' ');
	if (end_of_value == NULL)
	{
		current_position = *(data->current_position);
		length = ft_strlen(current_position);
		end_of_value = current_position + length;
	}
	if (end_of_value < *(data->current_position))
		return ;
	value_length = end_of_value - *(data->current_position);
	value_part = ft_strndup(*(data->current_position), value_length);
	append_chevron(data->head, data->types[data->token_index], value_part);
	free(value_part);
	*(data->current_position) = end_of_value;
}
