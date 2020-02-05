//
// Created by Concetta Pataki on 02/02/2020.
//

#include "fdf.h"

void    default_arg(fdf *data)
{
    data->x = 0;
    data->y = 0;
    data->zoom = 20;
    data->cos = 0.8;
    data->sin = 0.8;
    data->isometr = 1;
    data->z_zoom = 1;
    data->shift_x = 400;
    data->shift_y = 400;
}

int main(int argc, char **argv)
{
    fdf *data;
    if (argc != 2)
    {
        ft_putstr("usage: ./fdf map.fdf\n");
        exit(1);
    }
    data = (fdf*)malloc(sizeof(fdf));

    default_arg(data);
    read_file(argv[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
    return (0);
}