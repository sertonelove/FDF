/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:45:44 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 18:46:47 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_arg(t_fdf *data)
{
	data->zoom = 20;
	data->cos = 0.8;
	data->sin = 0.8;
	data->isometr = 1;
	data->z_zoom = 1;
	data->shift_x = 400;
	data->shift_y = 400;
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	argc_error(argc);
	data = (t_fdf*)malloc(sizeof(t_fdf));
	default_arg(data);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
