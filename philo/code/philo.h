/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:29 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/08 16:22:38 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_data	t_data;
/* ************************************************************************** */
/* ************************************************************************** */
typedef struct s_fork
{
	int			position;
	t_mutex		fork;

}	t_fork;
/* ************************************************************************** */
/* ************************************************************************** */
typedef struct s_philo
{
	int			position;
	long		nb_meals;
	bool		max_meals;
	t_fork		*first_fork;
	t_fork		*second_fork;
	long 		time_last_meal;
	pthread_t	thread_pos;
	t_data		*data;
}	t_philo;
/* ************************************************************************** */
/* ************************************************************************** */
struct s_data
{
	long		nb_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nb_meals_limit;
	long		begin;
	bool		end;
	bool		all_thread_ready;
	t_mutex		table_mutex;
	t_fork		*fork;
	t_philo		*philo;
};
/* ************************************************************************** */
/* ************************************************************************** */
typedef enum e_lexic
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_lexic;
/* ************************************************************************** */
/* ************************************************************************** */
/*Parsing*/
	void    	parsing(t_data *table, char **av);
	const char*	valid_input(const char *str);
	long		ft_atol(const char *str);
/*Init*/
	void		data_init(t_data *table);
/*Errors*/
	void 	ft_error(int index);
	void    *safe_malloc(size_t bytes);
	void    safe_mutex(t_mutex *mutex, t_lexic lexic);
	void 	safe_thread(pthread_t *thread, void *(*foo)(void *),
    			void *data, t_lexic lexic);
/*Mutex locks*/
	void    set_bool(t_mutex *mutex, bool *dest, bool value);
	bool    get_bool(t_mutex *mutex, bool *value);
	long    get_long(t_mutex *mutex, long *value);
	void    set_long(t_mutex *mutex, long *dest, long value);
	bool    diner_finished(t_data *table);
/*Synchronisation*/
	void 	wait_all_thread(t_data *table);
	void    *diner_simulation(void *data);
	void    diner_start(t_data *table);
	
#endif
