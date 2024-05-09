/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:47:05 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/09 20:25:31 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static void rev_rotate(t_stack_node **stack) //fait pivoter le nœud du bas d'une pile vers le sommet
{
    t_stack_node *last; 

    if (!*stack || !(*stack)->next) 
        return;
    last = find_last(*stack);
    last->prev->next = NULL; 
    last->next = *stack; 
    last->prev = NULL; 
    *stack = last; 
    last->next->prev = last; 
}

void rra(t_stack_node **a, bool print) // Fait pivoter le bas de `a` vers le sommet de la pile et imprime l'instruction
{
    rev_rotate(a);
    if (!print)
        ft_printf("\033[33mrra\n");
}

void rrb(t_stack_node **b, bool print) // Fait pivoter le bas de `b` vers le sommet de la pile et imprime l'instruction
{
    rev_rotate(b);
    if (!print)
        ft_printf("\033[33mrrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print) // Fait pivoter simultanément les nœuds du bas des deux piles vers le sommet de leurs piles, réduisant de moitié le coût des instructions
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("\033[33mrrr\n");
}
