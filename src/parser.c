/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:23:46 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:51:30 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_validator(char *map_path, t_data *data)
{
	if (!mapchecker(map_path))
		ft_error("Formato de archivo no válido");
	readmap(data, map_path);
	if (!surrounded_by_walls(data))
		ft_error("El mapa no está rodeado por muros");
	return (0);
}

int	process_map_line(t_data *data, char *map_line, int y)
{
	int	x;

	x = 0;
	while (map_line[x])
	{
		if (!ft_strchr("01PEC", map_line[x]))
			return (1);
		else if (map_line[x] == 'P')
			handle_p_position(data, x, y);
		else if (map_line[x] == 'E')
			handle_e_location(data, x, y);
		else if (map_line[x] == 'C')
			handle_c_instance(data);
		x++;
	}
	return (0);
}

int	allocate_memory_and_check_rectangular(char *map_line, t_data *data)
{
	data->size.x = ft_strlen(map_line);
	if (data->size.x != data->x_max)
	{
		return (1);
	}
	return (0);
}

int	parse_map(int fd, t_data *data)
{
	char	*map_line;
	char	*temp;
	int		error_code;

	data->size.y = 0;
	temp = get_next_line(fd);
	if (!temp)
		ft_error("File is a directory!");
	while (temp != NULL)
	{
		map_line = ft_strtrim(temp, "\n");
		error_code = process_map_line(data, map_line, data->size.y);
		if (error_code != 0)
			ft_error("Invalid map character found!");
		data->map[data->size.y] = map_line;
		data->map_copy[data->size.y++] = map_line;
		error_code = allocate_memory_and_check_rectangular(map_line, data);
		if (error_code != 0)
			ft_error("Invalid map shape!");
		free(temp);
		temp = get_next_line(fd);
	}
	data->coin_instances = malloc(sizeof(t_coin_instance *)
			* data->coin_instances_num);
	return (data->map[data->size.y] = NULL, 0);
}

int	surrounded_by_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size.x)
	{
		if (data->map[0][i] != '1' || data->map[data->size.y - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < data->size.y)
	{
		if (data->map[j][0] != '1' || data->map[j][ft_strlen(data->map[j])
			- 1] != '1')
			return (0);
		j++;
	}
	return (1);
}
