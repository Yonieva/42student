/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:23:02 by yonieva           #+#    #+#             */
/*   Updated: 2023/12/11 02:23:02 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/****************************************************************************/
/* message + sortie du jeu */
int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Snake ? Snake ?? Snaaaaaaaaaaaaaakkkke !!\n");
	ft_printf("GAME OVER\n");
	exit(EXIT_SUCCESS);
}
/****************************************************************************/



/****************************************************************************/
/* affiche la carte + enregistre donnees clavier-souris */
int	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}
/****************************************************************************/




/****************************************************************************/
int	main(int argc, char **argv)
{


	/* LANCEMENT DU PROGRAMME */
    /*Initialisation des Structures*/
	t_data	data;
	t_map	map;


    /*détermine la taille de la fenêtre selon les arguments argv*/
	ft_window_size(&data, argv);
    /*allocation de la mémoire pour la Carte*/
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		ft_printf("Erreur\nallocation echouee\n");
		exit(EXIT_FAILURE);
	}

 /*initialiser la structure de données*/
	ft_init(&data, &map);

    /*analyser les données de la carte*/
	ft_parse_input(&data, argv, argc);
  
  /*initialisation de MiniLibX*/
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_printf("Erreur\ninitialisation de la mlx echouee\n");
		exit(EXIT_FAILURE);
	}


	/*création de la Fenêtre*/
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "METAL GEAR 42");


    /*rendu première frame*/
	ft_render_next_frame(&data);

    /*boucle Principale + message si erreur et sortie*/
	mlx_loop(data.mlx);
	ft_printf("Erreur\nmlx_loop echoue\n");
	exit(EXIT_FAILURE);

}
/****************************************************************************/