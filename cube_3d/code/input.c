/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:50:16 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/24 12:50:16 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/game.h"


int key_press(int keycode, t_game *game) {
    if (keycode == ESC_KEY) {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    } else if (keycode == UP_KEY) {
        game->player_x += (int)(MOVE_SPEED * cos(game->player_angle));
        game->player_y += (int)(MOVE_SPEED * sin(game->player_angle));
    } else if (keycode == DOWN_KEY) {
        game->player_x -= (int)(MOVE_SPEED * cos(game->player_angle));
        game->player_y -= (int)(MOVE_SPEED * sin(game->player_angle));
    } else if (keycode == LEFT_KEY) {
        game->player_angle -= TURN_SPEED;
    } else if (keycode == RIGHT_KEY) {
        game->player_angle += TURN_SPEED;
    }
    return (0);
}

int update_game(t_game *game) {
    draw_background(game);
    draw_map(game);
    return (0);
}