/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sort_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:05:45 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/28 18:34:41 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib/push_swap.h"

void	sort_three(t_stack_node **a) //Gère lorsque la pile `a` a trois nœuds et la trie
{
	t_stack_node	*biggest_node; //Stocker un pointeur vers le plus gros nœud de la pile `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check si le noeud actuel et le plus gros
		ra(a, false); //si faux, rotate le noeud du sommet avec le dernier
	else if ((*a)->next == biggest_node) //Check si second noeud et +gros
		rra(a, false); //si faux, rotate le dernier noeud avec le premier
	if ((*a)->nbr > (*a)->next->nbr) //Vérifiez si le nœud inférieur est le plus grand, mais que le nœud supérieur est plus haut que le deuxième nœud
		sa(a, false); //Si tel est le cas, échangez simplement les nœuds supérieur et secondaire.
}

void	sort_stacks(t_stack_node **a, t_stack_node **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init_nodes_a(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_three(a);
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a); //Refresh the current position of stack `a`
	min_on_top(a); //Ensure smallest number is on top
}