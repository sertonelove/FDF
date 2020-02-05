//
// Created by Concetta Pataki on 05/02/2020.
//

#include "fdf.h"

void	draw_menu(fdf *data)
{
    char *menu;

    menu = "esc: exit program";
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 5, 0x03fc36, menu);
    menu = "1: 3d/2d mode; +, -: zoom";
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 20, 0x03fc36, menu);
    menu = "<, >: z-scale; 2, 3, 4, 5: rotation";
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 35, 0x03fc36, menu);
    menu = "w, s, a, d: moving";
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 50, 0x03fc36, menu);
}