//
// Created by Concetta Pataki on 05/02/2020.
//

#include "fdf.h"

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