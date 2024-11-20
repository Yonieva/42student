/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_expanser_env1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:01:36 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:01:36 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_var_name_env(const char *value, size_t *i)
{
	size_t	start;
	char	*var_name;

	start = *i;
	while (ft_isalnum(value[*i]) || value[*i] == '_')
		(*i)++;
	if (*i == start)
		return (ft_strdup(""));
	var_name = ft_strndup(&value[start], *i - start);
	return (var_name);
}

void	append_env_value_env(t_exp_data *data, const char *env_value)
{
	size_t	env_len;
	char	*new_result;

	env_len = ft_strlen(env_value);
	new_result = ft_realloc(data->result, data->j, data->j + env_len + 1);
	if (!new_result)
		return ;
	ft_memcpy(&new_result[data->j], env_value, env_len);
	data->j += env_len;
	data->result = new_result;
}

void	start_exp(const char *va, t_exp_data *data, char **env)
{
	char	*var_name;
	char	*env_value;

	var_name = extract_var_name_env(va, &(data->i));
	env_value = get_env_value(var_name, env);
	free(var_name);
	if (env_value)
		append_env_value_env(data, env_value);
}

char	*expand_variables_in_value(const char *value, char **env, t_envp *envp)
{
	t_exp_data	*data;
	char		*result;

	data = init_expansion_data(value);
	if (!data)
		return (NULL);
	while (data->i < data->len)
	{
		if (value[data->i] == '\'')
			is_single_quotes(value, data);
		else if (value[data->i] == '$'
			&& value[data->i + 1]
			&& !data->in_single_quotes)
			handle_variable_expansion(value, data, env, envp);
		else
			data->result[data->j++] = value[data->i++];
	}
	data->result[data->j] = '\0';
	result = data->result;
	free(data);
	return (result);
}

char	*clean_string(const char *str)
{
	t_exp_data	*data;
	char		*cleaned_str;

	data = init_expansion_data(str);
	if (!data)
		return (NULL);
	while (data->i < data->len)
	{
		if (str[data->i] == '\'' && !data->in_double_quotes)
			data->in_single_quotes = !data->in_single_quotes;
		else if (str[data->i] == '\"' && !data->in_single_quotes)
			data->in_double_quotes = !data->in_double_quotes;
		else if ((str[data->i] == '\'' && data->in_double_quotes)
			|| (str[data->i] == '\"' && data->in_single_quotes)
			|| (str[data->i] != '\'' && str[data->i] != '\"'))
			data->result[data->j++] = str[data->i];
		data->i++;
	}
	data->result[data->j] = '\0';
	cleaned_str = ft_strdup(data->result);
	free(data->result);
	free(data);
	return (cleaned_str);
}
