/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:52:54 by khuynh            #+#    #+#             */
/*   Updated: 2024/03/03 17:35:03 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	map_open(char *av, t_game *game, int fd)
{
	char	*line;
	char	*gnl;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (freeallexit2("Error\nLecture echouee\n", game), exit(-1), 0);
	gnl = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
		return (free(gnl), free(line), close (fd), 0);
	free(line);
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		gnl = ft_strjoin(gnl, line);
		free (line);
		game->y++;
	}
	game->map = ft_split(gnl, '\n');
	game->x = ft_strlen(game->map[0]);
	mapcopy(game);
	return (free(gnl), free(line), close(fd), 0);
}

int	mapcopy(t_game *game)
{
	int	x;
	int	y;

	game->mapcopy = ft_calloc(game->y + 1, (sizeof(char *)));
	if (!game->mapcopy)
		return (0);
	x = 0;
	y = 0;
	while (x < game->y)
	{
		game->mapcopy[x] = ft_calloc(game->x + 1, sizeof(char));
		if (!game->mapcopy)
			return (0);
		y = 0;
		while (game->map[x][y])
		{
			game->mapcopy[x][y] = game->map[x][y];
			y++;
		}
		x++;
	}
	game->mapcopy[x] = NULL;
	return (1);
}
