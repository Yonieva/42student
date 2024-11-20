/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_analyse3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:39 by acabarba          #+#    #+#             */
/*   Updated: 2024/10/15 18:56:12 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_inside_quotes(char current_char, bool *s_q_open, bool *d_q_open)
{
	if (current_char == '\'')
		*s_q_open = !(*s_q_open);
	else if (current_char == '\"')
		*d_q_open = !(*d_q_open);
	return (*s_q_open || *d_q_open);
}

char	*clean_whitespace(char *str)
{
	int		i;
	int		j;
	char	*cleaned_str;
	bool	s_q_open;
	bool	d_q_open;

	i = 0;
	j = 0;
	s_q_open = false;
	d_q_open = false;
	cleaned_str = safe_malloc(strlen(str) + 1);
	while (str[i])
	{
		if (is_inside_quotes(str[i], &s_q_open, &d_q_open))
			cleaned_str[j++] = str[i];
		else
		{
			if (str[i] != ' ' || (j > 0 && cleaned_str[j - 1] != ' '))
				cleaned_str[j++] = str[i];
		}
		i++;
	}
	cleaned_str[j] = '\0';
	return (cleaned_str);
}
