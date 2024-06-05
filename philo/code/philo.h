/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:29 by yonieva           #+#    #+#             */
/*   Updated: 2024/06/05 15:28:53 by yonieva          ###   ########.fr       */
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

typedef struct s_philosopher
{
	int					position;
	int					time_to_die;
	int					time_to_eat;
	int				    time_to_sleep;
    int                 must_eat;
}	t_philosopher;





/*Gestion d erreur*/
void    ft_error(int index);
void    check_arg(char *arg);



#endif
