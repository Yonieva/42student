/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:50:54 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/24 12:50:54 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/game.h"

void load_map(t_game *game) {
    FILE *file = fopen("assets/maps/map.txt", "r");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    int y = 0;
    while (fgets(game->map[y], sizeof(game->map[y]), file)) {
        game->map_width = strlen(game->map[y]) - 1;
        y++;
    }
    game->map_height = y;

    fclose(file);
}