/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:07:15 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/18 22:28:08 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../lib/so_long.h"


/****************************************************************************/
/*Verifs si map contient "1C0EP"*/
void	char_mapcheck(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->collect++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->posy = y;
		game->posx = x;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		freeallexit3("\033[0;31mLa map doit se composer uniquement de '0,1,P,E,C'\n\e[0m", game);
}
/****************************************************************************/





/****************************************************************************/
/*Affiche message d erreur lie a la map*/
void	charerror_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	if (!game->map)
		freemaps(game);
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			char_mapcheck(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->collect == 0)
		freeallexit3("\033[0;31mPas de Collectable !\n\e[0m", game);
	if (game->player == 0)
		freeallexit3("\033[0;31mPas de Joueur !\n\e[0m", game);
	if (game->player > 1)
		freeallexit3("\033[0;31mPlus de 1 Joueur !\n\e[0m", game);
	if (game->exit == 0 || game->exit > 1)
		freeallexit3("\033[0;31mAucune ou plusieurs Sorties ...\n\e[0m", game);
}
/****************************************************************************/


/****************************************************************************/
/*Verif si des murs entoure la map*/
void	walls_mapcheck(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1' || game->map[game->y - 1][j] != '1')
				freeallexit3("\033[0;31mUn ou plusieurs Murs manquants !\n\e[0m", game);
			if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
				freeallexit3("\033[0;31mUn ou plusieurs Murs manquants !\n\e[0m", game);
			j++;
		}
		i++;
	}
}
/****************************************************************************/






/****************************************************************************/
/*Verif si map rectangulaire*/
void	rectangular_mapcheck(t_game *game)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(game->map[0]);
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = ft_strlen(game->map[y]);
		if (x != size)
			freeallexit3("\033[0;31mLa Map n est pas rectangulaire !\n\e[0m", game);
		y++;
	}
}
