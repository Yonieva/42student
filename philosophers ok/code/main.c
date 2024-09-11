/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:48:50 by yonieva           #+#    #+#             */
/*   Updated: 2024/09/11 19:16:21 by yonieva          ###   ########.fr       */
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
	printf("***********     LE REPAS EST TERMINE     ***********\n");
	return (0);
}
