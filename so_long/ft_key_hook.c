/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:36:13 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/04 17:36:13 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/****************************************************************************/
	/*reagis aux touches pressees par le joueur*/
	/*declenche victoire si joueur a le collectable et se trouve sur la sortie*/
	int	ft_key_hook(int keycode, t_data *data)
	{
		if (keycode == ESC)
			ft_exit(data);
		else if (keycode == W)
			ft_move(data, 'y', UP);
		else if (keycode == A)
			ft_move(data, 'x', LEFT);
		else if (keycode == S)
			ft_move(data, 'y', DOWN);
		else if (keycode == D)
			ft_move(data, 'x', RIGHT);
		if (data->map->map[data->p_y][data->p_x] == 'E')
			ft_win(data);
		return (0);
	}
/****************************************************************************/