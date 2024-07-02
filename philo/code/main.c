/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:48:50 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/01 14:53:38 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
    int i;
    t_data  table;

    i = 1;
    if (ac == 5 || ac == 6)
    {
        parsing(&table, av);
        data_init(&table);
        diner_start(&table);
        clean(&table);
    }
    else
        ft_error(1);
    return(0)

}
