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

void ft_error(int index)
{
    if (index == 1)
    {
        printf("\033[33m🚨Erreur dans le nombre d arguments saisis🚨\n");
        return (EXIT_FAILURE);
    }
    if (index == 2)
    {
        printf("\033[33m🚨Une valeur saisie est negative !🚨\n");
        return (EXIT_FAILURE);
    }
    if (index == 3)
    {
        printf("\033[33m🚨Une valeur saisie n'est pas un nombre !🚨\n");
        return (EXIT_FAILURE);
    }
    if (index == 4)
    {
        printf("\033[33m🚨Une valeur saisie depasse la limite INT_MAX🚨\n");
        return (EXIT_FAILURE);
    }
    if (index == 5)
    {
        printf("\033[33m🚨Une valeur de temps depasse la limite 60ms🚨\n");
        return (EXIT_FAILURE);
    }
}