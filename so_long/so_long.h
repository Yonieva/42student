/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:23:58 by yonieva           #+#    #+#             */
/*   Updated: 2023/12/11 02:23:58 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H



# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct t_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int on_destroy(t_data *data);
int on_keypress(int keysym, t_data *data);

#endif
