/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:55:13 by yonieva           #+#    #+#             */
/*   Updated: 2024/08/17 23:19:24 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
		ft_error(2);
	if (!(*str >= '0' && *str <= '9'))
		ft_error(3);
	number = str;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		len++;
	}
	if (len > 10)
		ft_error(4);
	return (number);
}

long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		ft_error(4);
	return (num);
}

/*input en milisecond, conversion en microsecond pour usleep()*/

void	parsing(t_data *table, char **av)
{
	table->nb_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table-> time_to_sleep < 6e4)
		ft_error(5);
	if (av[5])
		table->nb_meals_limit = ft_atol(av[5]);
	else
		table->nb_meals_limit = -1;
}

void	clean(t_data *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->nb_philo)
	{
		philo = table->philo + i;
		safe_mutex(&philo->philo_mutex, DESTROY);
	}
	safe_mutex(&table->write_mutex, DESTROY);
	safe_mutex(&table->table_mutex, DESTROY);
	free(table->fork);
	free(table->philo);
}
