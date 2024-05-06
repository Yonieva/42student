/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:44:05 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/06 16:43:30 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int main(int argc, char **argv) // Définit un programme qui prend en entrée des nombres aléatoires et les trie par ordre croissant
{
	title();
	t_stack_node *a; // Pour stocker un pointeur vers la pile `a`
	t_stack_node *b; // Pour stocker un pointeur vers la pile `b`

	a = NULL; // Définit les deux pointeurs à NULL pour éviter un comportement indéfini
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) // Vérifie les nombres d'arguments incorrects ou si le 2e argument est `0`
		return (1);
	else if (argc == 2) // Vérifie si le nombre d'arguments est de 2 et si le 2e n'est pas vide, cela implique une chaîne de caractères
		argv = ft_split(argv[1], ' '); // Appelle `split()` pour extraire chaque sous-chaîne
	init_stack_a(&a, argv + 1); // Initialise la pile `a`, qui gère également les erreurs
	if (!stack_sorted(a)) // Vérifie si la pile n'est pas triée
	{
		if (stack_len(a) == 2) // Si non, et s'il y a deux nombres, échanger les deux premiers nœuds
			sa(&a, false);
		else if (stack_len(a) == 3) // Si non, et s'il y a trois nombres, appelle l'algorithme de tri à trois
			sort_three(&a);
		else
			sort_stacks(&a, &b); // Si non, et s'il y a plus de trois nombres, appelle l'algorithme de tri de piles
	}
	free_stack(&a); // Nettoie la pile
	return (0);
}