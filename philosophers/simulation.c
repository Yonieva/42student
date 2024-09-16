/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:44:13 by yonieva           #+#    #+#             */
/*   Updated: 2024/09/16 17:07:19 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo		*philosopher;
	t_data		*data;
	int			i;

	i = 0;
	philosopher = (t_philo *)philo;
	data = philosopher->philo_data;
	if (philosopher->philo_id % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&(data->mutex_eat));
	while (!(data->is_dead) && data->check_eat != 1)
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		eat_philo(philosopher);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philosopher->philo_id, "😴 ronfle 😴");
		pthread_mutex_unlock(&(data->mutex_eat));
		sleep_time(data->tt_sleep, data);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philosopher->philo_id, "🤔 reflechie sur la vie 🤔");
		i++;
	}
	pthread_mutex_unlock(&(data->mutex_eat));
	return (NULL);
}

void	eat_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->philo_data;
	pthread_mutex_lock(&(data->forks[philo->fork.left]));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "↪️ s'empare d'une fourchette 🍴");
	pthread_mutex_unlock(&(data->mutex_eat));
	pthread_mutex_lock(&(data->forks[philo->fork.right]));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "↪️ s'empare d'une fourchette 🍴");
	print_status(data, philo->philo_id, "🥵 est en train de s'empifrer 🥵");
	philo->time_philolastmeal = get_time();
	pthread_mutex_unlock(&(data->mutex_eat));
	sleep_time(data->tt_eat, data);
	pthread_mutex_lock(&(data->mutex_eat));
	(philo->philo_nbeat)++;
	pthread_mutex_unlock(&(data->mutex_eat));
	pthread_mutex_unlock(&(data->forks[philo->fork.right]));
	pthread_mutex_unlock(&(data->forks[philo->fork.left]));
}

void	sleep_time(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	pthread_mutex_lock(&(data->mutex_eat));
	while ((!((get_time() - i) >= time)) && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(50);
		pthread_mutex_lock(&(data->mutex_eat));
	}
	pthread_mutex_unlock(&(data->mutex_eat));
}
