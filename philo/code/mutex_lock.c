/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:55:48 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/04 16:55:48 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philo.h"

void    set_bool(t_mutex *mutex, bool *dest, bool value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

bool    get_bool(t_mutex *mutex, bool *value)
{
    bool ret;

    safe_mutex(mutex, LOCK);
    ret = *value;
    safe_mutex(mutex, UNLOCK);
    return (ret);
}

long    get_long(t_mutex *mutex, long *value)
{
    long    ret;

    safe_mutex(mutex, LOCK);
    ret = *value;
    safe_mutex(mutex, UNLOCK);
    return (ret);


}

void    set_long(t_mutex *mutex, long *dest, long value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

bool    diner_finished(t_data *table)
{
    return (get_bool(&table->table_mutex, &table->end));
}
