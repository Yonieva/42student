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


#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif



# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"


typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
}	t_data;

#endif
