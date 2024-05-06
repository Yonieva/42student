/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate .c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:51:08 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/06 16:04:51 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static void rotate(t_stack_node **stack) // Fait pivoter le nœud du sommet d'une pile vers le bas
{
    t_stack_node *last_node;

    if (!*stack || !(*stack)->next)
        return;
    last_node = ft_lstlast(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void ra(t_stack_node **a, bool print) // Fait pivoter le nœud supérieur `a` vers le bas de la pile, et imprime l'instruction
{
    rotate(a);
    if (!print)
        ft_printf("\033[33mra\n");
}

void rb(t_stack_node **b, bool print) // Fait pivoter le nœud supérieur `b` vers le bas de la pile, et imprime l'instruction
{
    rotate(b);
    if (!print)
        ft_printf("\033[33mrb\n");
}

void rr(t_stack_node **a, t_stack_node **b, bool print) // Fait pivoter simultanément les nœuds supérieurs `a` et `b` vers le bas de la pile, et imprime l'instruction
{
    rotate(a);
    rotate(b);
    if (!print)
        ft_printf("\033[33mrr\n");
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