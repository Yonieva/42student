/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:07:03 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/18 22:37:37 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../lib/so_long.h"

int	moveok(t_game *game, int x, int y, int key)
{
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'C')
		game->collect--;
	if (game->map[y][x] == 'E' && game->collect == 0)
	{
		game->complete = 1;
		ft_printf("Total Mouvements:%d\n", game->moves++);
		ft_printf("\nMISSION COMPLETED\n\n");
		freeallexit("", game);
		return (0);
	}
	else if (game->map[y][x] == 'E')
		return (1);
	if (key != 'w' && key != 's' && key != 'a' && key != 'd' && key != XK_Left
		&& key != XK_Right && key != XK_Up && key != XK_Down)
		return (1);
	else
		return (0);
}

void	movereset(t_game *game, int x, int y, int key)
{
	int	moveoky;
	int	col;
	int	lin;

	col = game->posx;
	lin = game->posy;
	moveoky = moveok(game, y, x, key);
	if (moveoky != 1)
	{
		game->map[col][lin] = '0';
		game->posx = x;
		game->posy = y;
		game->map[x][y] = 'P';
		ft_printf("Manoeuvre:%d\n", game->moves++);
	}
}

int	keyactions(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->posx;
	y = game->posy;
	if (key == 'a' || key == XK_Left)
		y--;
	else if (key == 'w' || key == XK_Up)
		x--;
	else if (key == 's' || key == XK_Down)
		x++;
	else if (key == 'd' || key == XK_Right)
		y++;
	else if (key == 65307)
		freeallexit("", game);
	if (game->complete != 1)
		movereset(game, x, y, key);
	return (0);
}
