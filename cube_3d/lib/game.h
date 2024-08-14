/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:52:29 by yonieva           #+#    #+#             */
/*   Updated: 2024/07/24 12:52:29 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#define WIDTH 800
#define HEIGHT 600
#define TILE_SIZE 32
#define MOVE_SPEED 5
#define TURN_SPEED 0.1
#define ESC_KEY 53
#define UP_KEY 126
#define DOWN_KEY 125
#define LEFT_KEY 123
#define RIGHT_KEY 124

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_game 
{
    void *mlx;
    void *win;
    void *wall_img;
    int   img_width;
    int   img_height;
    char **map;
    int map_width;
    int map_height;
    int player_x;
    int player_y;
    float player_angle;
}   t_game;

int init_game(t_game *game);
void cleanup_game(t_game *game);
void game_loop(t_game *game);
int update_game(t_game *game);
void load_map(t_game *game);
void draw_background(t_game *game);
void draw_map(t_game *game);
void draw_wall(t_game *game, int x, int y);
void load_assets(t_game *game);
int key_press(int keycode, t_game *game);
void load_map(t_game *game);
#endif
