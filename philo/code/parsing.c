/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:55:13 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/08 16:40:03 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

const char *valid_input(const char *str)
{
    int len;
    const char  *number;

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

long ft_atol(const char *str)
{
    long num;
    
    num = 0;
    str = valid_input(str);
    while (*str >= '0' && *str <= '9')
        num = (num * 10) + (*str++ - 48);
    if (num > INT_MAX)
        ft_error(4);
    return (num);
}
/*input en milisecond, conversion en microsecond pour usleep()*/
void    parsing(t_data *table, char **av)
{
    table->nb_philo = ft_atol(av[1]);
    table->time_to_die = ft_atol(av[2]) * 1000;
    table->time_to_eat = ft_atol(av[3]) * 1000;
    table->time_to_sleep = ft_atol(av[4]) * 1000;
    if (table->time_to_die > 60000 
        || table->time_to_eat > 60000
        || table-> time_to_sleep > 60000)
        ft_error(5);
    if (av[5])
        table->nb_meals_limit = ft_atol(av[5]);
    else
        table->nb_meals_limit = -1;
}
