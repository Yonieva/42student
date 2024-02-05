/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:11 by yonieva           #+#    #+#             */
/*   Updated: 2024/01/24 20:02:11 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_data *data, char **argv)
/* détermine taille fenêtre selon argv + erreur si non .ber  */
{
	int	fd;

	if (argv[1] == NULL)
	{
    	ft_printf("Erreur : Nom de fichier NULL\n");
    	exit(EXIT_FAILURE);
	}

	ft_printf("Ouverture du fichier : %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erreur\nExemple : './so_long map/map1.ber'\n");
		exit(EXIT_FAILURE);
	}
	int line_length = ft_line_length(fd);
	ft_printf("Longueur de la première ligne : %d\n", line_length);
	if (strcmp(ft_strchrr(argv[1], '.'), ".ber") != 0)
	{
		ft_printf("Erreur\nFomat carte '.ber' non reconnue\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
	ft_printf("Taille de la fenêtre (data->size_x) : %d\n", data->size_x);
	ft_printf("Taille de la fenêtre (data->size_y) : %d\n", data->size_y);
}





void	ft_create_map(t_data *data)
/*  remplit la carte de textures en fonction caractere dans .ber */
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_object(data, "./assets/texture_map/mur_haut.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_object(data, "./assets/texture_item/card.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_object(data, "./assets/texture_item/exit.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}