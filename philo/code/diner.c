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

static void thinking(t_philo *philo)
{
    write_status(THINKING, philo, DEBUG_MODE);
}

static void eat(t_philo *philo)
{
    /*****************/
    /*1--grab forks*/
    /*****************/
    safe_mutex(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
    /******************************/
    /*2--eat/update last meal, full*/
    /******************************/
    set_long(&philo->philo_mutex, &philo->time_last_meal, get_time(MILLISECOND));
    philo->nb_meals++;
    write_status(EATING, philo, DEBUG_MODE);
    precise_usleep(philo->data->time_to_eat, philo->data);
    if (philo->data->nb_meals_limit > 0
        && philo->nb_meals == philo->data->nb_meals_limit)
        set_bool(&philo->philo_mutex, &philo->full, true);
    /******************************/
    /*3--UNLOCK*/
    /******************************/
    safe_mutex(&philo->first_fork->fork, UNLOCK);
    safe_mutex(&philo->second_fork->fork, UNLOCK);
}

void    *diner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_thread(philo->data);
    while(!diner_finished(philo->data))
    {
        /*im full ?*/
        if (philo->full)
            break;
        /*im eating*/
        eat(philo);
        /*sleeping*/
        write_status(SLEEPING, philo, DEBUG_MODE);
        precise_usleep(philo->data->time_to_sleep, philo->data);
        /*thinking*/
        thinking(philo);
    }
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
    {
        while(i < table->nb_philo)
        {
            safe_thread(&table->philo[i].thread_pos, diner_simulation, 
                &table->philo[i], CREATE);
            i++;
        }
    }
    /*moniteur des morts*/
    safe_thread(&table->monitor, monitor_dinner, table, CREATE);
    /*debut de du diner*/
    table->begin = get_time(MILLISECOND);
    /*tout les threads philo sont prets*/
    set_bool(&table->table_mutex, &table->all_thread_ready, true);
     /*Attendre tout le monde*/
     i = 0;
     while(i < table->nb_philo)
     {
        safe_thread(&table->philo[i].thread_pos, NULL, NULL, JOIN);
        i++;
     }
}