/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:36:01 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 18:41:04 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shift_and_zoom(int key, t_fdf *data)
{
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
}

int		deal_key(int key, t_fdf *data)
{
	ft_shift_and_zoom(key, data);
	if (key == 19)
		data->cos += 0.1;
	if (key == 20)
		data->cos -= 0.1;
	if (key == 21)
		data->sin += 0.1;
	if (key == 23)
		data->sin -= 0.1;
	if (key == 18)
		((data->isometr == 1) ? (data->isometr = 0)
	: (data->isometr = 1));
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
