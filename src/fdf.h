/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:47:02 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 19:15:05 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>

typedef	struct	s_fdf
{
	float		x1;
	float		y1;
	float		cos;
	float		sin;
	float		x_step;
	float		y_step;
	int			isometr;
	int			height;
	int			width;
	int			**matrix_z;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			z_zoom;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void			read_file(char *file_name, t_fdf *data);
void			compound(float x, float y, int temp, t_fdf *data);
void			draw(t_fdf *data);
void			draw_menu(t_fdf *data);
int				deal_key(int key, t_fdf *data);
void			ft_temp(int temp, float x, float y, t_fdf *data);
void			isometric(float *x, float *y, int z, t_fdf *data);
void			ft_zoom(float *x, float *y, t_fdf *data);
void			ft_shift(float *x, float *y, t_fdf *data);
void			ft_z_zoom(int *z, int *z1, t_fdf *data);
void			ft_max(float *max, t_fdf *data);
void			validate_map(char *line, int *temp);
void			not_valid_error(char *line, int *temp);
void			not_exist_error(char *file_name, int *fd);
void			argc_error(int argc);

#endif
