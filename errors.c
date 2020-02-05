//
// Created by Concetta Pataki on 05/02/2020.
//

#include "fdf.h"

void    not_valid_error(char *line, int *temp)
{
    if (*temp == 1)
    {
        ft_putstr("map file not a valid!\n");
        free(line);
        exit(0);
    }
}

void    not_exist_error(char *file_name, int fd)
{
    if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
    {
        ft_putstr("file does not exist!\n");
        exit(0);
    }
}

void    argc_error(int argc)
{
    if (argc != 2)
    {
        ft_putstr("usage: ./fdf map.fdf\n");
        exit(0);
    }
}