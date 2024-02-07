/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:51:34 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:25:12 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_data *data)
{
	int	c;

	c = 0;
	while (data->map[c] != NULL)
	{
		free(data->map[c]);
		c++;
	}
	free(data->map);
	c = 0;
	while (data->map_copy[c] != NULL)
	{
		free(data->map_copy[c]);
		c++;
	}
	free(data->map_copy);
	free(data);
}

static int	allocate_map(char *line, t_data *data, int fd, char *map_path)
{
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Empty map\n"), EXIT_FAILURE);
	while (line != NULL)
	{
		data->lines++;
		data->size.x = ft_strlen(line);
		if (data->size.x)
			data->size.x--;
		if (data->x_max < data->size.x)
			data->x_max = data->size.x;
		free(line);
		line = get_next_line(fd);
	}
	data->map = ft_calloc(data->lines + 1, sizeof(char *));
	data->map_copy = ft_calloc(data->lines + 1, sizeof(char *));
	if (!data->map || !data->map_copy)
		return (free(line), EXIT_FAILURE);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el archivo");
	if ((parse_map(fd, data)) == 1)
		return (free(line), EXIT_FAILURE);
	return (close(fd), EXIT_SUCCESS);
}

int	readmap(t_data *data, char *map_path)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el archivo");
	if (allocate_map(line, data, fd, map_path) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
