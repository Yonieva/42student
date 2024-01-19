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

#include "so_long.h"


int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return (0);
}

int on_keypress(int keysym, t_data *data)
{
    (void)data;
    printf("Pressed key: %d\n", keysym);
    return (0);
}




int main(void)
{
 t_data data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "METAL GEAR 42");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);

    // Chargement de l'image
    void *img;
    char *relative_path = "./assets/texture_map/sol.xpm";
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
    if (!img)
        return (free(data.mlx_ptr), 1);

    // Affichage de l'image
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 0, 0);

    // Enregistre touches relâchées
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

    // Enregistre les destructions
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    // Boucle sur le pointeur MLX
    mlx_loop(data.mlx_ptr);
    return (0);
}