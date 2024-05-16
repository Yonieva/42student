/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:51:08 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/13 14:18:53 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

//fait pivoter le nœud du sommet d'une pile vers le bas
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

//fait pivoter le nœud supérieur `a` vers le bas de la pile
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

//fait pivoter le nœud supérieur `b` vers le bas de la pile
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

//fait pivoter simultanément les nœuds supérieurs `a` et `b`vers le bas
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

/*Avant la rotation :

	NULL
   +---+
   | C |  <- *stack
   |   |
   +---+
   | B |
   |   |
   +---+
   | A |
   |   |
   +---+
   NULL

Après la rotation :

	NULL
   +---+
   | B |  <- *stack
   |   |
   +---+
   | A |
   |   |
   +---+
   | C |
   |   |
   +---+
	NULL 
*/