//
// Created by Concetta Pataki on 03/02/2020.
//

#include "fdf.h"

/*void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}*/

void    isometric(float *x, float *y, int z, float cos, float sin)
{
    *x = (*x - *y) * cos;
    *y = (*x + *y) * sin - z;
}

/*void    isometric_z1(fdf *data)
{
    data->x = (data->x - data->y) * cos(0.8);
    data->y = (data->x + data->y) * sin(0.8) - data->z1;
}*/

/*void    ft_zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x *= data->zoom;
    *y *= data->zoom;
    *x1 *= data->zoom;
    *y1 *= data->zoom;
}*/

void    ft_zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x *= data->zoom;
    *y *= data->zoom;
    *x1 *= data->zoom;
    *y1 *= data->zoom;
}

/*void    ft_shift(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}*/

void    ft_shift(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}

void    ft_z_zoom(int *z, int *z1, fdf *data)
{
    *z *= data->z_zoom;
    *z1 *= data->z_zoom;
}

void    compound(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    float max;
    int z;
    int z1;

    z = data->matrix_z[(int)y][(int)x];
    z1 = data->matrix_z[(int)y1][(int)x1];
    ft_z_zoom(&z, &z1, data);
    ft_zoom(&x, &y, &x1, &y1, data);

    data->color = (z || z1) ? 0xe80c0c : 0xffffff;

    if (data->isometr == 1)
    {
        isometric(&x, &y, z, data->cos, data->sin);
        isometric(&x1, &y1, z1, data->cos, data->sin);
    }
    x_step = x1 - x;
    y_step = y1 - y;

    ft_shift(&x, &y, &x1, &y1, data);

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *data)
{
    int x;
    int y;

    draw_menu(data);
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                compound(x, y, x + 1, y, data);
            if (y < data->height - 1)
                compound(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}