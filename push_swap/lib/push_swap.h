/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:39:59 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/28 18:31:09 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

/* ************************************************************************** */
void	title(void)
{
ft_printf("\033 ____  _   _ ____  _   _     ______        ___    ____        \n"); 
ft_printf("\033|  _ \\| | | / ___|| | | |   / ___\\ \\      / / \\  |  _ \\  \n");
ft_printf("\033| |_) | | |  ___\\\\| |_| |    \\___ \\ \\ /\\ / / _ \\ | |_)|\n");
ft_printf("\033|  __/| |_|  ___) |  _  |    ___) |\\ V  V / ___ \\|  __/     \n");
ft_printf("\033|_|    \\___/|____/|_| |_|___|____/  \\_/\\_/_/   \\_\\_|     \n");
}
/* ************************************************************************** */
typedef struct s_stack_node
{
    int                 nbr; // Le nombre à trier
    int                 index; // La position du nombre dans la pile
    int                 push_cost; // Le nombre total de commandes
    bool                above_median; // Utilisé pour calculer `push_cost`
    bool                cheapest; // Le nœud le moins coûteux pour effectuer des commandes
    struct s_stack_node *target_node; // Le nœud cible d'un nœud dans la pile opposée
    struct s_stack_node *next; // Un pointeur vers le prochain nœud
    struct s_stack_node *prev; // Un pointeur vers le nœud précédent
} t_stack_node;

/* ************************************************************************** */
/*COMMANDES PUSH*/
static void push(t_stack_node **dst, t_stack_node **src);
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

/*COMMANDES ROTATE*/
static void rotate(t_stack_node **stack);
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES REV_ROTATE*/
static void rev_rotate(t_stack_node **stack);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES SWAP*/
static void swap(t_stack_node **head);
void    sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES SORT_STACK*/
static void rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node);
static void rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node);
static void move_a_to_b(t_stack_node **a, t_stack_node **b);                              
static void	move_b_to_a(t_stack_node **a, t_stack_node **b);
static void	min_on_top(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	sort_three(t_stack_node **a);
/* ************************************************************************** */
/*STACK_TOOLS*/
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);







#endif

