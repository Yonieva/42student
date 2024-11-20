/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_mini_export3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:37:51 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	insertion_sort(char **array, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < size)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(array[j], temp) > 0)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
		i++;
	}
}

char	**copy_env(char **env, int size)
{
	char	**sorted_env;
	int		i;

	sorted_env = malloc(size * sizeof(char *));
	if (!sorted_env)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted_env[i] = env[i];
		i++;
	}
	return (sorted_env);
}

void	print_sorted_env(char **env)
{
	char	**sorted_env;
	int		size;
	int		i;
	char	*equal_sign;

	size = get_env_size(env);
	sorted_env = copy_env(env, size);
	if (!sorted_env)
		return ;
	insertion_sort(sorted_env, size);
	i = 0;
	while (i < size)
	{
		equal_sign = strchr(sorted_env[i], '=');
		if (equal_sign == NULL)
			printf("declare -x %s\n", sorted_env[i]);
		else if (equal_sign[1] == '\0')
			printf("declare -x %.*s=\"\"\n",
				(int)(equal_sign - sorted_env[i]), sorted_env[i]);
		else
			printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
	free(sorted_env);
}
