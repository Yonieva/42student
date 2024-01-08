/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:23:02 by yonieva           #+#    #+#             */
/*   Updated: 2023/12/11 02:23:02 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"
# include "mlx/mlx.h"
 

# define MLX_ERROR 1
#include <mlx.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
