/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:06:12 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/02 00:06:12 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	printf("WWOOOOOOOOOOOOOOOOOOOOOOOOOOOO.\n");
	printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}