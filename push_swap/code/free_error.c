/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:42:49 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/27 17:11:12 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

// Définit une fonction pour gérer les erreurs de syntaxe,
//et renvoie `1` en cas d'erreur si l'une des conditions suivantes est remplie
int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

// fonction qui vérifie les doublons des nombres d'entrée dans la pile `a`
int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// Définit une fonction pour libérer une pile en cas d'erreurs
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Définit une fonction qui, lorsqu'elle rencontre une erreur unique,
//libère la pile et affiche un message d'erreur
void	free_errors(t_stack	**a, char **tab)
{
	free_stack(a);
	free_tab(tab);
	ft_printf("Erreur\n");
	exit(1);
}
