//
// Created by Concetta Pataki on 05/02/2020.
//

#include "fdf.h"

void    check_strings(int *i, int *temp)
{
    static int  width_string;

    if (!width_string)
        width_string = *i;
    else if (width_string > 0 && width_string != *i)
        *temp = 1;
}

void    validate_map(char *line, int *temp)
{
    char		**numb;
    int			i;
    int			j;

    i = 0;
    j = 0;
    numb = ft_strsplit(line, ' ');
    *temp = 0;
    while (numb[i])
    {
        j = 0;
        while (numb[i][j])
        {
            if (!(numb[i][j] >= 48 && numb[i][j] <= 57) && numb[i][j] != '\n' &&
                numb[i][j] != '-')
                *temp = 1;
            j++;
        }
        free(numb[i]);
        i++;
    }
    free(numb);
    check_strings(&i, *&temp);
}