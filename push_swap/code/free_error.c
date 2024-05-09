/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:42:49 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/09 17:42:49 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

// Définit une fonction pour gérer les erreurs de syntaxe, et renvoie `1` en cas d'erreur si l'une des conditions suivantes est remplie
int error_syntax(char *str_n) 
{
    if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9'))) // Vérifie si le premier caractère de la chaîne d'entrée ne contient ni de signe ni de chiffre
        return (1);
    if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9')) // Vérifie si le premier caractère de la chaîne d'entrée contient un signe, mais que le deuxième caractère ne contient pas de chiffre
        return (1);
    while (*++str_n) { // Si les conditions d'erreur ci-dessus sont satisfaites, pré-incrémente pour pointer vers le caractère suivant dans la chaîne, et boucle jusqu'à ce que la fin de la chaîne soit atteinte
        if (!(*str_n >= '0' && *str_n <= '9')) // Vérifie si le caractère suivant dans la chaîne n'est pas un chiffre
            return (1);
    }
    return (0);
}

// Définit une fonction qui vérifie les doublons des nombres d'entrée dans la pile `a`
int error_duplicate(t_stack_node *a, int n) 
{
    if (!a) // Vérifie une pile vide
        return (0);
    while (a) { // Boucle jusqu'à ce que la fin de la pile `a` soit atteinte
        if (a->nbr == n) // Vérifie si la valeur du nœud actuel est égale à `n`. Se référer à `init_stack_a()`
            return (1);
        a = a->next; // Passe au nœud suivant pour vérifier les doublons
    }
    return (0);
}

// Définit une fonction pour libérer une pile en cas d'erreurs
void free_stack(t_stack_node **stack) 
{
    t_stack_node *tmp; // Pour stocker le prochain nœud de la pile avant que le nœud actuel ne soit libéré, car une fois qu'un nœud est libéré, vous ne pouvez pas accéder à son pointeur suivant
    t_stack_node *current;

    if (!stack) // Vérifie une pile vide
        return;
    current = *stack;
    while (current) { // Tant qu'un nœud existe dans la pile
        tmp = current->next; // Affecte à `tmp` le pointeur vers le nœud suivant
        current->nbr = 0; // Affecter le nœud à `0` avant la libération n'est pas strictement nécessaire mais peut aider à détecter d'éventuels bogues tels que les fuites de mémoire et améliorer le débogage
        free(current); // Libère le nœud actuel, libérant la mémoire occupée par ce nœud
        current = tmp; // Affecte `tmp` comme le premier nœud actuel
    }
    *stack = NULL;
}

// Définit une fonction qui, lorsqu'elle rencontre une erreur unique, libère la pile et affiche un message d'erreur
void free_errors(t_stack_node **a) 
{
    free_stack(a);
    ft_printf("\033[31mErreur\n");
    exit(1);
}