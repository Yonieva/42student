/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:47:05 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/22 15:48:08 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static void rev_rotate(t_stack_node **stack) // Définit une fonction qui fait pivoter le nœud du bas d'une pile vers le sommet
{
    t_stack_node *last; // Pour stocker le pointeur vers le dernier nœud

    if (!*stack || !(*stack)->next) // Vérifie si la pile est vide, ou s'il y a un seul nœud
        return;
    last = find_last(*stack);
    last->prev->next = NULL; // Affecte à l'attribut `next` du nœud précédent lui-même, `NULL` le définissant efficacement comme le dernier nœud actuel
    last->next = *stack; // Affecte à son propre attribut `next` le sommet de la pile
    last->prev = NULL; // Le détache du nœud précédent
    *stack = last; // Achève son ajout au sommet de la pile, et détient désormais le pointeur vers le sommet
    last->next->prev = last; // Met à jour le dernier nœud actuel de la pile
}

void rra(t_stack_node **a, bool print) // Fait pivoter le bas de `a` vers le sommet de la pile et imprime l'instruction
{
    rev_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void rrb(t_stack_node **b, bool print) // Fait pivoter le bas de `b` vers le sommet de la pile et imprime l'instruction
{
    rev_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print) // Fait pivoter simultanément les nœuds du bas des deux piles vers le sommet de leurs piles, réduisant de moitié le coût des instructions
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}