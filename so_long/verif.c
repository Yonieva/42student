/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:35:35 by yonieva           #+#    #+#             */
/*   Updated: 2024/01/24 19:35:35 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




/****************************************************************************/
/* imprime message d'erreur specifique et quitte le jeu */
void	ft_map_error(char *error_msg)
{
	printf("%s", error_msg);
	exit(EXIT_FAILURE);
}
/****************************************************************************/





/****************************************************************************/
/*  vérifie si la carte est entoure par des murs et possede des elements connus */
void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_map_error("Erreur\nmap non rectangulaire !\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_map_error("Erreur\nelements '0','1','C','P','E' non valide\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_map_error("Erreur\nla map doit etre entoure par des murs !\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_map_error("Error\nla map doit etre entoure par des murs !\n");
			x++;
		}
		y++;
	}
}
/****************************************************************************/





/****************************************************************************/
/* verifie si la carte est valide */
void	ft_check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->card = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_item(data->map->map[y], 'E');
		player += ft_count_item(data->map->map[y], 'P');
		data->map->card += ft_count_item(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("Erreur\n+ de 1 joueur detecte sur la map\n");
	if (exit == 0)
		ft_map_error("Erreur\n0 sortie detectee sur la map\n");
	if (data->map->card == 0)
		ft_map_error("Erreur\n0 collectable detecte sur la map\n");
}
/****************************************************************************/




/****************************************************************************/
/* verifie si les arguments de l utlisateur sont valides */
void	ft_input_error(int	argc)
{
	if (argc != 2)
	{
		ft_map_error("Erreur : Le nombre d'argument doit etre de 1\n");
		exit(EXIT_FAILURE);
	}
}
/****************************************************************************/





/****************************************************************************/
/* lis fichier.ber, construit la carte dans t_data, verifie la carte */
void	ft_parse_input(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
    	perror("Erreur lors de l'ouverture du fichier");
    	exit(EXIT_FAILURE);
	}
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_borders(data);
}
/****************************************************************************/