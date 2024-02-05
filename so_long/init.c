/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:09:40 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/02 02:09:40 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
static void	ft_init_help(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/texture_player/snake_right.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/texture_map/sol.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
}
*/


/* initialises most of my used data inside the structs */
void	ft_init(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Erreur\nallocation echouee!!\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "assets/texture_player/snake_up.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/texture_player/snake_left.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/texture_player/snake_down.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/texture_player/snake_right.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/texture_map/sol.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	data->counter = 0;
	data->collected = 0;
}