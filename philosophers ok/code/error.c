/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:25:31 by yonieva           #+#    #+#             */
/*   Updated: 2024/06/19 14:25:31 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int index)
{
	if (index == 1)
		printf("\033[33m🚨Erreur dans le nombre d arguments saisis🚨\n");
	if (index == 2)
		printf("\033[33m🚨Une valeur saisie est negative !🚨\n");
	if (index == 3)
		printf("\033[33m🚨Une valeur saisie n'est pas un nombre !🚨\n");
	if (index == 4)
		printf("\033[33m🚨Une valeur saisie depasse la limite INT_MAX🚨\n");
	if (index == 5)
		printf("\033[33m🚨Une valeur de temps est en dessous de 60ms🚨\n");
	if (index == 6)
		return (exit(EXIT_FAILURE));
	return (exit(EXIT_FAILURE));
}

/*ERREURS DE MEMOIRE****************************************************/
void	*safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (ptr == NULL)
	{
		printf("\033[33m🚨Erreur d allocation de memoire🚨\n");
		ft_error(6);
	}
	return (ptr);
}

/*MUTEX & THREAD SAFE***************************************************/
static void	error_mutex_or_pthread(int status)
{
	fputs("\n\e[1A", stdout);
	if (status == 0)
		return ;
	else
	{
		printf("\033[33m🚨Erreur de Mutex ou de Thread !🚨\n");
		ft_error(6);
	}
}

void	safe_mutex(t_mutex *mutex, t_lexic lexic)
{
	if (LOCK == lexic)
		error_mutex_or_pthread(pthread_mutex_lock(mutex));
	else if (UNLOCK == lexic)
		error_mutex_or_pthread(pthread_mutex_unlock(mutex));
	else if (INIT == lexic)
		error_mutex_or_pthread(pthread_mutex_init(mutex, NULL));
	else if (DESTROY == lexic)
		error_mutex_or_pthread(pthread_mutex_destroy(mutex));
	else
	{
		printf("\033[33m🚨Erreur de Mutex !🚨\n");
		ft_error(6);
	}
}

void	safe_thread(pthread_t *thread, void *(*foo)(void *),
	void *data, t_lexic lexic)
{
	if (CREATE == lexic)
		error_mutex_or_pthread(pthread_create(thread, NULL, foo, data));
	else if (JOIN == lexic)
		error_mutex_or_pthread(pthread_join(*thread, NULL));
	else if (DETACH == lexic)
		error_mutex_or_pthread(pthread_detach(*thread));
	else
	{
		printf("\033[33m🚨Erreur de Pthread !🚨\n");
		ft_error(6);
	}
}
