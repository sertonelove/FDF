//
// Created by Concetta Pataki on 03/02/2020.
//

#include "fdf.h"

void    isometric(float *x, float *y, int z, fdf *data)
{
    *x = (*x - *y) * data->cos;
    *y = (*x + *y) * data->sin - z;
}

void    ft_zoom(float *x, float *y, fdf *data)
{
    *x *= data->zoom;
    *y *= data->zoom;
    data->x1 *= data->zoom;
    data->y1 *= data->zoom;
}

void    ft_shift(float *x, float *y, fdf *data)
{
    *x += data->shift_x;
    *y += data->shift_y;
    data->x1 += data->shift_x;
    data->y1 += data->shift_y;
}

void    ft_z_zoom(int *z, int *z1, fdf *data)
{
    *z *= data->z_zoom;
    *z1 *= data->z_zoom;
}

void    compound(float x, float y, int temp, fdf *data)
{
    float x_step;
    float y_step;
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
    x_step = data->x1 - x;
    y_step = data->y1 - y;

    ft_shift(&x, &y, data);

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - data->x1) || (int)(y - data->y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}