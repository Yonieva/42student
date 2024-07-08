/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:04:01 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/08 16:04:01 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    wait_all_thread(t_data *table)
{
    while (!get_bool(&table->table_mutex, &table->all_thread_ready))
        ;
}