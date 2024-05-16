/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:42:49 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/15 16:54:32 by yonieva          ###   ########.fr       */
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
int	error_duplicate(t_stack_node *a, int n)
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

// Définit une fonction pour libérer une pile en cas d'erreurs
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

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
void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("\033[31mErreur\n");
	exit(1);
}
