/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:08:30 by yonieva           #+#    #+#             */
/*   Updated: 2024/01/24 19:08:30 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



/****************************************************************************/
/* remplit l'écran avec une image de fond */
void	ft_put_background(t_data *data)

{
	int		y;
	int		x;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}
/****************************************************************************/




/****************************************************************************/
/* place un objet à la position définie par data->map->x et data->map->y*/
void	ft_put_object(t_data *data, char *relative_path)

{
	int		img_width;
	int		img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
		    &img_width, &img_height);

	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}
/****************************************************************************/







/****************************************************************************/
/* place le joueur dans la position de départ et regardant vers le haut)*/
void	ft_put_player(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}
/****************************************************************************/