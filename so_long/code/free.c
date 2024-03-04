/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:54:25 by yonieva           #+#    #+#             */
/*   Updated: 2024/03/03 17:31:26 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
/* ************************************************************************** */
/*parkour rows de la map et free  mémoire pour chq row/idem copie de la carte.*/
void	freemaps(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		freeallexit2("\033[0;31mError\nMap vide\n\e[0m", game);
	while (game->map[i])
	{
		free(game->map[i]);
		free(game->mapcopy[i]);
		i++;
	}
	free(game->map);
	free(game->mapcopy);
}
/* ************************************************************************** */

/* ************************************************************************** */
/*appel freemaps/detruit fenetre/detruit images/detruit affichage.*/
int	freefinal(t_game *game)
{
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxwin != NULL)
		mlx_destroy_window(game->mlxptr, game->mlxwin);
	if (game->img.c != NULL)
		mlx_destroy_image(game->mlxptr, game->img.c);
	if (game->img.p != NULL)
		mlx_destroy_image(game->mlxptr, game->img.p);
	if (game->img.e != NULL)
		mlx_destroy_image(game->mlxptr, game->img.e);
	if (game->img.w != NULL)
		mlx_destroy_image(game->mlxptr, game->img.w);
	if (game->img.f != NULL)
		mlx_destroy_image(game->mlxptr, game->img.f);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}
/* ************************************************************************** */

/*idem freefinal, mais elle affiche d'abord un message d'erreur*/
/* ************************************************************************** */
int	freeallexit(char *error, t_game *game)
{
	ft_printf("%s", error);
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxwin != NULL)
		mlx_destroy_window(game->mlxptr, game->mlxwin);
	if (game->img.c != NULL)
		mlx_destroy_image(game->mlxptr, game->img.c);
	if (game->img.p != NULL)
		mlx_destroy_image(game->mlxptr, game->img.p);
	if (game->img.e != NULL)
		mlx_destroy_image(game->mlxptr, game->img.e);
	if (game->img.w != NULL)
		mlx_destroy_image(game->mlxptr, game->img.w);
	if (game->img.f != NULL)
		mlx_destroy_image(game->mlxptr, game->img.f);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}
/* ************************************************************************** */

/*lorsque une partie des data doit être libérée en cas d'err.
affiche msg err et free l'affichage.*/
/* ************************************************************************** */
int	freeallexit2(char *error, t_game *game)
{
	ft_printf("%s", error);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}
/* ************************************************************************** */

/*idem freeallexit mai ne free pas  (game->mlxptr)*/
/* ************************************************************************** */
int	freeallexit3(char *error, t_game *game)
{
	ft_printf("%s", error);
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}
/* ************************************************************************** */