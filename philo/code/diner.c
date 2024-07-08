/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:25:01 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/02 14:25:01 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*si [0] en repas -> return*/
/*si 1 seul philo  -> return*/
/*1-creer threads et philos*/
/*2-Creer un affichage du deroulement du repas*/
/*3-Synchronniser le debut du repas
    quand thread cree -> le philo begin !
    nous voulons que tout les philos start same time*/

void    *diner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_thread(philo->data);
    return (NULL);
}   

void    diner_start(t_data *table)
{
    int i;

    i = 0;
    if (table->nb_meals_limit == 0)
        return ;
    //else if (table->nb_philo == 1)
    // to do 
    else
        while(i < table->nb_philo)
        {
            safe_thread(&table->philo[i].thread_pos, diner_simulation, 
                &table->philo[i], CREATE);
            i++;
        }
    /*thread ready*/
    set_bool(&table->table_mutex, &table->all_thread_ready, true);
}