//
// Created by Concetta Pataki on 03/02/2020.
//

#include "fdf.h"

void    compound(float x, float y, int temp, fdf *data)
{
    float max;
    int z;
    int z1;

    ft_temp(temp, x, y, data);
    z = data->matrix_z[(int)y][(int)x];
    z1 = data->matrix_z[(int)data->y1][(int)data->x1];
    ft_z_zoom(&z, &z1, data);
    ft_zoom(&x, &y, data);
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    if (data->isometr == 1)
    {
        isometric(&x, &y, z, data);
        isometric(&data->x1, &data->y1, z1, data);
    }
    data->x_step = data->x1 - x;
    data->y_step = data->y1 - y;
    ft_shift(&x, &y, data);
    ft_max(&max, data);
    while ((int)(x - data->x1) || (int)(y - data->y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += data->x_step;
        y += data->y_step;
    }
}