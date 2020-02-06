/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:34:14 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 18:35:23 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * data->cos;
	*y = (*x + *y) * data->sin - z;
}

void	ft_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
}

void	ft_shift(float *x, float *y, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
}

void	ft_z_zoom(int *z, int *z1, t_fdf *data)
{
	*z *= data->z_zoom;
	*z1 *= data->z_zoom;
}

void	ft_max(float *max, t_fdf *data)
{
	*max = MAX(MOD(data->x_step), MOD(data->y_step));
	data->x_step /= *max;
	data->y_step /= *max;
}
