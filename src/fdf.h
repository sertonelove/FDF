//
// Created by Concetta Pataki on 02/02/2020.
//

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>

typedef struct
{
    float x1;
    float y1;
    float cos;
    float sin;
    float x_step;
    float y_step;
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
void    compound(float x, float y, int temp, fdf *data);
void    draw(fdf *data);
void	draw_menu(fdf *data);
int deal_key(int key, fdf *data);
void	ft_temp(int temp, float x, float y, fdf *data);
void    isometric(float *x, float *y, int z, fdf *data);
void    ft_zoom(float *x, float *y, fdf *data);
void    ft_shift(float *x, float *y, fdf *data);
void    ft_z_zoom(int *z, int *z1, fdf *data);
void    ft_max(float *max, fdf *data);
void    validate_map(char *line, int *temp);
void    not_valid_error(char *line, int *temp);
void    not_exist_error(char *file_name, int *fd);
void    argc_error(int argc);

#endif