/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:03 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/18 22:35:56 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../lib/so_long.h"

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
		ft_putstr_fd("Erreur arguments, ex : './so_long/maps/test.ber'", 2);
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

int	main(int ac, char **av)
{
	t_game	game;

	argcheck(ac, av);
	init_struct(&game);
	map_open(av[1], &game, 0);
	charerror_map(&game);
	rectangular_mapcheck(&game);
	walls_mapcheck(&game);
	if (path_ok(&game))
	{
		game.mlxwin = mlx_new_window(game.mlxptr, game.x * 64,
				game.y * 64, "METAL GEAR 42");
		xpmtoimage(&game);
		mlx_loop_hook(game.mlxptr, displaygame, &game);
		mlx_hook(game.mlxwin, 02, 1L << 0, keyactions, &game);
		mlx_hook(game.mlxwin, 33, 0L, freefinal, &game);
		mlx_loop(game.mlxptr);
		free(game.mlxptr);
	}
	return (0);
}
