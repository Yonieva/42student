/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:48:50 by yonieva           #+#    #+#             */
/*   Updated: 2024/08/17 23:15:43 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	table;

	if (ac == 5 || ac == 6)
	{
		parsing(&table, av);
		data_init(&table);
		diner_start(&table);
		clean(&table);
	}
	else
		ft_error(1);
	printf("\033[32m***********     LE REPAS EST TERMINE     ***********\n");
	return (0);
}
