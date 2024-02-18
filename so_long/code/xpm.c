/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:23 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/18 22:29:16 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../lib/so_long.h"

void	xpmtoimage(t_game *game)
{
	game->img.c = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/c.xpm", &game->img.width, &game->img.height);
	game->img.e = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/e.xpm", &game->img.width, &game->img.height);
	game->img.p = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/p.xpm", &game->img.width, &game->img.height);
	game->img.w = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/w.xpm", &game->img.width, &game->img.height);
	game->img.f = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/f.xpm", &game->img.width, &game->img.height);
	if (!game->img.c || !game->img.e || !game->img.p || !game->img.w
		|| !game->img.f)
		freeallexit("Erreur mlx_xpm\n", game);
}

void	imgtowin(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.c, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.p, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.e, x * 64, y * 64);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.w, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.f, x * 64, y * 64);
}

int	displaygame(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (game->mlxwin)
	{
		while (game->map[++x])
		{
			y = 0;
			while (game->map[x][y])
			{
				imgtowin(game, x, y);
				y++;
			}
		}
	}
	return (0);
}
