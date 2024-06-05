/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:24 by yonieva           #+#    #+#             */
/*   Updated: 2024/06/05 15:28:46 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_error(int index)
{
    if (index == 1)
    {
        printf("Erreur(s) dans les arguments saisies par l'utilisateur");
        return (EXIT_FAILURE)
    }
}