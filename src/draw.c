/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:41:28 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 18:43:15 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_temp(int temp, float x, float y, t_fdf *data)
{
	if (temp == 1)
	{
		data->x1 = x + 1;
		data->y1 = y;
	}
	else
	{
		data->x1 = x;
		data->y1 = y + 1;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	draw_menu(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				compound(x, y, 1, data);
			if (y < data->height - 1)
				compound(x, y, 0, data);
			x++;
		}
		y++;
	}
}
