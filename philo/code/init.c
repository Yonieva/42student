/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:49:56 by yonieva           #+#    #+#             */
/*   Updated: 2024/08/17 23:13:09 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* si philo pos paire, premiere fork  = pos philo - 1*/
/* deuxieme fork = pos philo % nb philo*/

static void	assign_forks(t_philo *philo, t_fork *fork, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->data->nb_philo;
	philo->first_fork = &fork[(philo_position + 1) % philo_nbr];
	philo->second_fork = &fork[philo_position];
	if (philo->position % 2 == 0)
	{
		philo->first_fork = &fork[philo_position];
		philo->second_fork = &fork[(philo_position + 1) % philo_nbr];
	}
}

static void	init_philo(t_data *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->nb_philo)
	{
		philo = table->philo + i;
		philo->position = i + 1;
		philo->full = false;
		philo->nb_meals = 0;
		philo->data = table;
		safe_mutex(&philo->philo_mutex, INIT);
		assign_forks(philo, table->fork, i);
		i++;
	}
}

void	data_init(t_data *table)
{
	int	i;

	i = 0;
	table->end = false;
	table->all_thread_ready = false;
	table->philo = safe_malloc(sizeof(t_philo) * table->nb_philo);
	table->fork = safe_malloc(sizeof(t_fork) * table->nb_philo);
	table->thread_running_nb = 0;
	safe_mutex(&table->table_mutex, INIT);
	safe_mutex(&table->write_mutex, INIT);
	while (i < table->nb_philo)
	{
		safe_mutex(&table->fork[i].fork, INIT);
		table->fork[i].position = i;
		i++;
	}
	init_philo(table);
}

void	increase_long(t_mutex *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}
