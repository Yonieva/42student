/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_struct_expenser_gestion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:25:03 by acabarba          #+#    #+#             */
/*   Updated: 2024/08/17 19:32:31 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exp_data	*init_expansion_data(const char *value)
{
	t_exp_data	*data;

	data = (t_exp_data *)malloc(sizeof(t_exp_data));
	if (!data)
		return (NULL);
	data->i = 0;
	data->j = 0;
	data->in_single_quotes = 0;
	data->in_double_quotes = 0;
	data->len = ft_strlen(value);
	data->result = safe_malloc(data->len * 2 + 1);
	if (!data->result)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

void	free_expansion_data(t_exp_data *data)
{
	if (data)
	{
		if (data->result)
			free(data->result);
		free(data);
	}
}
