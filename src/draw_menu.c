/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:43:31 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 19:03:55 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *data)
{
	char *menu;

	menu = "esc: exit program";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 5, 0xe80c0c, menu);
	menu = "1: 3d/2d mode; +, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 20, 0xe80c0c, menu);
	menu = "<, >: z-scale; 2, 3, 4, 5: rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 35, 0xe80c0c, menu);
	menu = "w, s, a, d: moving";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 50, 0xe80c0c, menu);
}
