/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:49:19 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/24 12:49:19 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/game.h"

void draw_background(t_game *game) {
    mlx_clear_window(game->mlx, game->win);
}

void draw_map(t_game *game) {
    int x, y;

    for (y = 0; y < game->map_height; y++) {
        for (x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == '1') {
                draw_wall(game, x, y);
            }
        }
    }
}


void draw_wall(t_game *game, int x, int y) {
    mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
}

void load_assets(t_game *game) {
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "../xpm/w.xpm", &game->img_width, &game->img_height);
    if (!game->wall_img) {
        fprintf(stderr, "Error loading wall image\n");
        exit(EXIT_FAILURE);
    }
}


int init_game(t_game *game) {
    game->mlx = mlx_init();
    if (!game->mlx) {
        perror("mlx_init");
        return (1);
    }

    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Castlevania 2D");
    if (!game->win) {
        perror("mlx_new_window");
        return (1);
    }

    load_map(game);
    game->player_x = WIDTH / 2;
    game->player_y = HEIGHT / 2;
    game->player_angle = 0.0;

    return (0);
}

void cleanup_game(t_game *game) {
    mlx_destroy_window(game->mlx, game->win);
}

void game_loop(t_game *game) {
    mlx_loop_hook(game->mlx, update_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
    mlx_loop(game->mlx);
}