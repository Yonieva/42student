/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:44:05 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/09 20:37:43 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"


void	title(void)
{
	ft_printf("\033 ____  _   _ ____  _   _     ______        ___    ____        \n"); 
	ft_printf("\033|  _ \\| | | / ___|| | | |   / ___\\ \\      / / \\  |  _ \\  \n");
	ft_printf("\033| |_) | | |  ___\\\\| |_| |    \\___ \\ \\ /\\ / / _ \\ | |_)|\n");
	ft_printf("\033|  __/| |_|  ___) |  _  |    ___) |\\ V  V / ___ \\|  __/     \n");
	ft_printf("\033|_|    \\___/|____/|_| |_|___|____/  \\_/\\_/_/   \\_\\_|     \n");
}

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
		if (stack_len(a) == 2) //  Swap les deux premiers nœuds
			sa(&a, false);
		else if (stack_len(a) == 3) //  l'algorithme de tri à trois
			sort_three(&a);
		else
			sort_stacks(&a, &b); //  plus de trois nombres, appelle l'algorithme de tri de piles
	}
	else
		ft_printf("Nombres deja dans l ordre croisant, retour au terminal...\n\n");
	free_stack(&a); // Nettoie la pile
	return (0);
}