/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:03 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/24 12:57:11 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/game.h"
/****************************************************************************/
/*Verifs des arguments*/
void	argcheck(int ac, char **av)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";
	if (ac < 2 || ac > 2)
	{
		ft_putstr_fd("Err nbrs d'arguments, ex: './so_long/maps/test.ber'", 2);
		exit (EXIT_FAILURE);
	}
	while (av[1][i])
		i++;
	while (j < 4)
	{
		i--;
		j++;
	}
	j = 0;
	if (av[1][i++] != ber[j++])
	{
		ft_putstr_fd("Erreur fichier .ber non reconnu", 2);
		exit (EXIT_FAILURE);
	}
}
/***************************************************************************/

/***************************************************************************/
/*Lancement du programme*/
int	main(int ac, char **av)
{
	t_game	game;

	argcheck(ac, av);
	if (init_game(&game) != 0) 
    	return (1);
    game_loop(&game);
    cleanup_game(&game);
    return (0);
}
/***************************************************************************/