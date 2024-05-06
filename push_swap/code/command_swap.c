/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:57:40 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/06 16:05:52 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static void	swap(t_stack_node **head) // Définit une fonction qui échange les positions du nœud en haut et du second nœud d'une pile
{
	if (!*head || !(*head)->next) // Vérifie si le nœud en haut, ou le second nœud de la pile existe
		return ;
	*head = (*head)->next; // Met à jour `head` pour pointer vers le prochain nœud, échangeant ainsi les premier et second nœuds
	(*head)->prev->prev = *head; // Met à jour le pointeur `prev` du nœud avant le `new head` pour pointer vers le `new head`
	(*head)->prev->next = (*head)->next; // Met à jour le pointeur `next` du nœud avant le `new head` pour sauter l'ancien `head` et pointer directement vers le `new head`
	if ((*head)->next) // Vérifie s'il y a un nœud `next` après le `new head`
		(*head)->next->prev = (*head)->prev; // Si oui, met à jour son pointeur `prev` pour pointer vers le `new head`
	(*head)->next = (*head)->prev; // Met à jour le pointeur `next` du `new head` pour pointer vers l'ancien `head`, inversant ainsi leurs positions
	(*head)->prev = NULL; // Définit le pointeur `prev` du `new head` à `NULL`, complétant ainsi l'échange
}

void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("\033[36msa\n");
}

void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("\033[36msb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("\033[36mss\n");
}