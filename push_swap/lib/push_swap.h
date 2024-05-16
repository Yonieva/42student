/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:39:59 by yonieva           #+#    #+#             */
/*   Updated: 2024/05/15 15:22:45 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

char	**split_modified(char *s, char c);
/* ************************************************************************** */
/* ************************************************************************** */
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

/* ************************************************************************** */
/* ************************************************************************** */
/*COMMANDES PUSH*/
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

/*COMMANDES ROTATE*/
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

/*COMMANDES REV_ROTATE*/
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

/*COMMANDES SWAP*/
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

/*COMMANDES SORT_STACK + ALGO TURC*/
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);
/* ************************************************************************** */
/* ************************************************************************** */
/*STACK_TOOLS*/
t_stack	*find_last(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
/* ************************************************************************** */
/* ************************************************************************** */
/*STACK_INIT*/
void	init_stack_a(t_stack **a, char **argv);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node,
			char stack_name);
/* ************************************************************************** */
/* ************************************************************************** */
/*ERROR*/
int		error_syntax(char *str_n);
int		error_duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
/* ************************************************************************** */
/* ************************************************************************** */
/*INIT A TO B*/
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
/*INIT B TO A*/
void	init_nodes_b(t_stack *a, t_stack *b);
/* ************************************************************************** */
/* ************************************************************************** */
#endif
