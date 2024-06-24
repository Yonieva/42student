/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:29 by yonieva           #+#    #+#             */
/*   Updated: 2024/06/19 16:02:36 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>


typedef pthread_mutex_t t_mutex;

/* ************************************************************************** */
typedef struct s_philo
{
	int			position;
	long		nb_meals;
	bool		max_meals;
	t_fork		*l_fork;
	t_fork		*r_fork;
	long 		time_last_meal;
	pthread_t	thread_pos;
	t_data		*data;
}	t_philo;

typedef struct s_fork
{
	int			position;
	t_mutex		fork;

}	t_fork;

typedef struct s_data
{
	long		nb_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nb_meals_limit;
	long		begin;
	bool		end;
	t_fork		*fork;
	t_philo		*philo;
}	t_data;
/* ************************************************************************** */
/*Parsing*/
	void    	parsing(t_table *table);
	const char*	valid_input(const char *str)
	long		ft_atol(const char *str)
	void    	ft_error(int index);

/*Init*/



#endif
