/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:49:56 by yonieva           #+#    #+#             */
/*   Updated: 2024/06/25 17:54:57 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*fork droite = pos philo - 1*/
/*fork gauche = pos philo % nb philo*/
static void assign_forks(t_philo *philo, t_fork *fork, int philo_position)
{
    int philo_nbr;

    philo_nbr = philo->table->philo_nbr;
    philo->r_fork = &fork[philo_position];
    philo->left_fork = &fork[(philo_position + 1) % philo_nbr];
}

static void init_philo(t_table *table)
{
    int i;
    t_philo *philo;

    i = 0;
    while(i < table->nb_philo)
    {
        philo = table->philo + i;
        philo->position = i + 1;
        philo->max_meals = false;
        philo->nb_meals = 0;
        philo->data = table;
        assign_forks(philo, table->fork, i);
        i++;
    } 
}

void    data_init(t_data *table)
{
    int i;

    i = 0;
    table->end = false;
    table->philo = safe_malloc(sizeof(t_philo) * table->nb_philo);
    table->fork = safe_malloc(sizeof(t_fork) * table->nb_philo);
    while (i < table->nb_philo)
    {
        safe_mutex(&table->fork[i].fork, INIT);
        table->fork[i].position = i; // pour debug
        i++;
    }
    init_philo(table);
}