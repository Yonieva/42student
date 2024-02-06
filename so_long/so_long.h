/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:23:58 by yonieva           #+#    #+#             */
/*   Updated: 2024/01/09 15:08:13 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ********** Pour system Linux ********** */
#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
/* ********** Pour system MacOS ********** */
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif


/* ********** Inclusions des bibliotheques ********** */
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

/****************************************************************************/


/* ********** definitions taille ecran + touches pour clavier mac ********** */

# define IMG_W 1024
# define IMG_H 1080
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
/****************************************************************************/


/****************************************************************************/
/* ***** stock images pour chaque position du joueur ***** */
typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;
/****************************************************************************/



/****************************************************************************/
/* ***** stock map, pointeur vers objet, coord du joueur + comptr obj ***** */
typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		card;
}				t_map;
/****************************************************************************/



/****************************************************************************/
/* ***** stocker toutes les données du programme ***** */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;
/****************************************************************************/


/****************************************************************************/
/* ********** Taille fenetre + enregistrement des hooks ********** */
void	ft_window_size(t_data *data, char **argv);
int		ft_key_hook(int keycode, t_data *data);
int		ft_mouse_hook(int mousecode, t_data *data);
void	ft_move(t_data *data, char position, int direction);
int		ft_key_hook(int keycode, t_data *data);

/* ********** La Map ********** */
void	ft_create_map(t_data *data);
int		ft_count_lines(int fd, int x, int img_w); 
int		ft_line_length(int fd);
int		ft_count_item(char *s, char c);
void	ft_put_object(t_data *data, char *relative_path);
void	ft_put_player(t_data *data);
void	ft_parse_input(t_data *data, char **argv, int argc);
void	ft_put_background(t_data *data);
void	ft_init(t_data *data, t_map *map);
int 	ft_render_next_frame(t_data *data);    

/* ********** Personnage ********** */
void	ft_player_move(t_data *data, char position, int direction);
void	ft_collect(t_data *data, char pos, int dir);
void	ft_move(t_data *data, char pos, int dir);

/* ********** Verifs ********** */
void	ft_map_error(char *error_msg);
void	ft_check_borders(t_data *data);
void	ft_check_content(t_data *data);
void	ft_input_error(int	argc);

/* ********** Sortie victoire + sortie erreur ********** */
void	ft_win(t_data *data);
int		ft_exit(t_data *data);
/****************************************************************************/


#endif
