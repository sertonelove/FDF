//
// Created by Concetta Pataki on 02/02/2020.
//

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>

typedef struct
{
    float cos;
    float sin;
    int isometr;
    int height;
    int width;
    int **matrix_z;
    int zoom;
    int color;
    int shift_x;
    int shift_y;
    int z_zoom;

    void *mlx_ptr;
    void *win_ptr;
}       fdf;

void    read_file(char *file_name, fdf *data);
void    compound(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);
void	draw_menu(fdf *data);
void    compound(float x, float y, float x1, float y1, fdf *data);
int deal_key(int key, fdf *data);

#endif