/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:32:55 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/10 23:32:55 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*[time millisecond] [philo pos] [action]*/

static void	write_status_debug(t_philo_status status, t_philo *philo, long elapsed)

{
	if (TAKE_FIRST_FORK == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d ↪️s'empare de sa premiere fourchette [🍴 en position %d]\n", elapsed, philo->position, philo->first_fork->position);
	else if (TAKE_SECOND_FORK == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d ↪️s'empare de sa seconde fourchette [🍴 en position %d]\n", elapsed, philo->position, philo->second_fork->position);
	else if (EATING == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d 🥵est en train de s'empifrer🥵[ %ld 🍲 engloutis au total ]\n", elapsed, philo->position, philo->nb_meals);
	else if (SLEEPING == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d 😴est en train de ronfler😴\n", elapsed, philo->position);
	else if (THINKING == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d 🤔fait mine de reflechir🤔\n", elapsed, philo->position);
	else if (DIED == status && !diner_finished(philo->data))
		printf("%6ld⏲️ Philo %d 💀a succomber a tous ces efforts ...💀\n", elapsed, philo->position);  
}

void    write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long elapsed;

	elapsed = get_time(MILLISECOND) - philo->data->begin;

	if (philo->full)
		return ;
	safe_mutex(& philo->data->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !diner_finished(philo->data))
			printf("%-6ld    %d prend une fourchette\n", elapsed, philo->position);
		else if (EATING == status && !diner_finished(philo->data))
			printf("%-6ld    %d mange\n", elapsed, philo->position);
		else if (SLEEPING == status && !diner_finished(philo->data))
			printf("%-6ld    %d dort\n", elapsed, philo->position);
		else if (THINKING == status && !diner_finished(philo->data))
			printf("%-6ld    %d reflechie\n", elapsed, philo->position);
		else if (DIED == status && !diner_finished(philo->data))
			printf("%-6ld    %d mort\n", elapsed, philo->position);   
	}
	safe_mutex(& philo->data->write_mutex, UNLOCK);
}

void	*monitor_dinner(void *data)
{
	t_data *table;

	table = (t_data *)data;
	while (!all_thread_running())
	return (NULL);
}