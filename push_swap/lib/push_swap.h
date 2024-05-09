/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:39:59 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/09 20:33:35 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

void	title(void);
/* ************************************************************************** */
/* ************************************************************************** */
typedef struct s_stack_node
{
    int                 nbr; // Le nombre à trier
    int                 index; // La position du nombre dans la pile
    int                 push_cost; // Le nombre total de commandes
    bool                above_median; // Utilisé pour calculer `push_cost`
    bool                cheapest; // Le nœud le moins coûteux 
    struct s_stack_node *target_node; // Le nœud cible d'un nœud pil opposée
    struct s_stack_node *next; // Un pointeur vers le prochain nœud
    struct s_stack_node *prev; // Un pointeur vers le nœud précédent
} t_stack_node;

/* ************************************************************************** */
/* ************************************************************************** */
/*COMMANDES PUSH*/
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

/*COMMANDES ROTATE*/
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES REV_ROTATE*/
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES SWAP*/
void    sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

/*COMMANDES SORT_STACK + ALGO TURC*/
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
/* ************************************************************************** */
/* ************************************************************************** */
/*STACK_TOOLS*/
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
bool    stack_sorted(t_stack_node *stack);
int     stack_len(t_stack_node *stack);
/* ************************************************************************** */
/* ************************************************************************** */
/*STACK_INIT*/
void        init_stack_a(t_stack_node **a, char **argv);
t_stack_node    *get_cheapest(t_stack_node *stack);
void prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name);
/* ************************************************************************** */
/* ************************************************************************** */
/*ERROR*/
int error_syntax(char *str_n);
int error_duplicate(t_stack_node *a, int n);
void free_stack(t_stack_node **stack);
void free_errors(t_stack_node **a);
/* ************************************************************************** */
/* ************************************************************************** */
/*INIT A TO B*/
void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
/*INIT B TO A*/
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
/* ************************************************************************** */
/* ************************************************************************** */
#endif
