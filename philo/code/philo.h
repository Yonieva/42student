/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:29 by yonieva           #+#    #+#             */
/*   Updated: 2024/08/17 23:27:57 by yonieva          ###   ########.fr       */
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
# define DEBUG_MODE	1

typedef pthread_mutex_t	t_mutex;
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
	bool		full;
	t_fork		*first_fork;
	t_fork		*second_fork;
	long		time_last_meal;
	pthread_t	thread_pos;
	t_mutex		philo_mutex;
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
	long		thread_running_nb;
	bool		end;
	bool		all_thread_ready;
	pthread_t	monitor;
	t_mutex		table_mutex;
	t_mutex		write_mutex;
	t_fork		*fork;
	t_philo		*philo;
};
/* ************************************************************************** */
/* ************************************************************************** */
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;
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
typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time;
/* ************************************************************************** */
/* ************************************************************************** */
/*Parsing*/
void		parsing(t_data *table, char **av);
const char	*valid_input(const char *str);
long		ft_atol(const char *str);
void		clean(t_data *table);
/*Init*/
void		data_init(t_data *table);
/*Errors*/
void		ft_error(int index);
void		*safe_malloc(size_t bytes);
void		safe_mutex(t_mutex *mutex, t_lexic lexic);
void		safe_thread(pthread_t *thread, void *(*foo)(void *),
				void *data, t_lexic lexic);
/*Mutex locks*/
void		set_bool(t_mutex *mutex, bool *dest, bool value);
bool		get_bool(t_mutex *mutex, bool *value);
long		get_long(t_mutex *mutex, long *value);
void		set_long(t_mutex *mutex, long *dest, long value);
bool		diner_finished(t_data *table);
/*Synchronisation*/
void		wait_all_thread(t_data *table);
long		get_time(t_time time_code);
void		precise_usleep(long usec, t_data *table);
void		increase_long(t_mutex *mutex, long *value);
bool		all_thread_running(t_mutex *mutex, long *threads, long nb_philo);
void		desynchro(t_philo *philo);
/*Diner*/	
void		*diner_simulation(void *data);
void		diner_start(t_data *table);
void		thinking(t_philo *philo, bool value);
/*Affichage*/
void		write_status(t_philo_status status, t_philo *philo, bool debug);
void		*monitor_dinner(void *data);
void		*alone_philo(void *arg);
#endif
