/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:55:24 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/06 19:00:40 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int			get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void		fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void		read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;
	int		temp;

	not_exist_error(file_name, &fd);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix_z = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->matrix_z[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		validate_map(line, &temp);
		not_valid_error(line, &temp);
		fill_matrix(data->matrix_z[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->matrix_z[i] = NULL;
}
