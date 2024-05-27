/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:05:45 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/27 16:54:40 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

//Gère lorsque la pile `a` a trois nœuds et la trie
void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

//bouge le +petit nb en haut de la pile
void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

char	**add_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	while (i < argc - 1)
	{
		tab[i] = ft_strdup(argv[i + 1]);
		if (!tab[i])
		{
			free_tab(tab);
			return (tab);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
