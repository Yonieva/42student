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
/*si 1 seul philo  -> alone_philo*/
/*1-creer threads et philos*/
/*2-Creer un affichage du deroulement du repas*/
/*3-Synchronniser le debut du repas
	quand thread cree -> le philo begin !
	nous voulons que tout les philos start same time*/

void	thinking(t_philo *philo, bool value)
{
	long	time_eat;
	long	time_sleep;
	long	time_think;

	if (!value)
		write_status(THINKING, philo, DEBUG_MODE);
	if (philo->data->nb_philo % 2 == 0)
		return ;
	time_eat = philo->data->time_to_eat;
	time_sleep = philo->data->time_to_sleep;
	time_think = time_eat * 2 - time_sleep;
	if (time_think < 0)
		time_think = 0;
	precise_usleep(time_think * 0.42, philo->data);
}

void	*alone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_thread(philo->data);
	set_long(&philo->philo_mutex, &philo->time_last_meal, get_time(MILLISECOND));
	increase_long(&philo->data->table_mutex, &philo->data->thread_running_nb);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!diner_finished(philo->data))
		usleep(200);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->time_last_meal,
		get_time(MILLISECOND));
	philo->nb_meals++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->nb_meals_limit > 0
		&& philo->nb_meals == philo->data->nb_meals_limit)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
	safe_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*diner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_thread(philo->data);
	set_long(&philo->philo_mutex, &philo->time_last_meal,
		get_time(MILLISECOND));
	increase_long(&philo->data->table_mutex, &philo->data->thread_running_nb);
	desynchro(philo);
	while (!diner_finished(philo->data))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, false);
	}
	return (NULL);
}

void	diner_start(t_data *table)
{
	int	i;

	i = -1;
	if (table->nb_meals_limit == 0)
		return ;
	else if (table->nb_philo == 1)
		safe_thread(&table->philo[0].thread_pos, alone_philo, &table->philo[0], CREATE);
	else
	{
		while (++i < table->nb_philo)
		{
			safe_thread(&table->philo[i].thread_pos, diner_simulation,
				&table->philo[i], CREATE);
		}
	}
	safe_thread(&table->monitor, monitor_dinner, table, CREATE);
	table->begin = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_thread_ready, true);
	i = -1;
	while (++i < table->nb_philo)
		safe_thread(&table->philo[i].thread_pos, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->end, true);
	safe_thread(&table->monitor, NULL, NULL, JOIN);
}
