//
// Created by Concetta Pataki on 02/02/2020.
//

#include "fdf.h"

int deal_key(int key, fdf *data)
{
    printf("%d\n", key);

    if (key == 126 || key == 13)
        data->shift_y -= 10;
    if (key == 125 || key == 1)
        data->shift_y += 10;
    if (key == 123 || key == 0)
        data->shift_x -= 10;
    if (key == 124 || key == 2)
        data->shift_x += 10;
    if (key == 24 || key == 69)
        data->zoom += 5;
    if (key == 27 || key == 78)
        data->zoom -= 5;
    if (key == 19)
        data->cos += 0.1;
    if (key == 20)
        data->cos -= 0.1;
    if (key == 21)
        data->sin += 0.1;
    if (key == 23)
        data->sin -= 0.1;
    if (key == 18)
        ((data->isometr == 1) ? (data->isometr = 0) : (data->isometr = 1));
    if (key == 47)
        data->z_zoom += 1;
    if (key == 43)
        data->z_zoom -= 1;
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        free(data->matrix_z);
        exit(0);
    }
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

void    default_arg(fdf *data)
{
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