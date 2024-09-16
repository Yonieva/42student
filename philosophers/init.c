/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:44 by yonieva           #+#    #+#             */
/*   Updated: 2024/09/16 16:14:34 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = data->philos;
	data->time_simstart = get_time();
	while (i < data->philo_nb)
	{
		pthread_create(&(ph[i].n_thread), NULL, routine, &(ph[i]));
		pthread_mutex_lock(&(data->mutex_eat));
		ph[i].time_philolastmeal = get_time();
		pthread_mutex_unlock(&(data->mutex_eat));
		i++;
	}
	is_dead(data, ph);
	end_sim(data);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->philo_nb = ft_atoi(argv[1]);
	data->tt_death = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	data->check_eat = 0;
	if (argc == 6)
		data->tt_meal = ft_atoi(argv[5]);
	else
		data->tt_meal = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	data->philos = malloc(sizeof(t_philo) * data->philo_nb);
	init_mutex(data);
	start(data);
}

/* si philo pos paire, fork left = pos philo*/
/* fork right = pos philo +1 % nb philo*/
void	init_mutex(t_data *data)
{
	int	i;

	i = data->philo_nb;
	data->is_dead = 0;
	pthread_mutex_init(&(data->mutex_print), NULL);
	pthread_mutex_init(&(data->mutex_eat), NULL);
	while (--i >= 0)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].philo_id = i + 1;
		data->philos[i].philo_nbeat = 0;
		if (data->philos[i].philo_id % 2 == 0)
		{
			data->philos[i].fork.left = i;
			data->philos[i].fork.right = (i + 1) % data->philo_nb;
		}
		else
		{
			data->philos[i].fork.left = (i + 1) % data->philo_nb;
			data->philos[i].fork.right = i;
		}
		data->philos[i].time_philolastmeal = 0;
		data->philos[i].philo_data = data;
	}
}

void	end_sim(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = data->philos;
	if (data->philo_nb == 1)
		pthread_mutex_unlock(&(data->forks[ph[0].fork.left]));
	while (i < data->philo_nb)
	{
		pthread_join(ph[i].n_thread, NULL);
		i++;
	}
	i = 0;
	while (++i < data->philo_nb)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->mutex_print));
	pthread_mutex_destroy(&(data->mutex_eat));
	free(data->forks);
	free(data->philos);
	exit (0);
}
