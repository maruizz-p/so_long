/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:23:46 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/12/14 16:07:06 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_validator(char *map_path, t_params *params)
{
	int	fd;

	if (!mapchecker(map_path))
		ft_error("Formato de archivo no válido");
	fd = open(map_path);
	if (fd < 0)
		ft_error("Error al abrir el archivo");
	parse_map(fd, params);
	if (!surrounded_by_walls(params))
		ft_error("El mapa no está rodeado por muros");
	close(fd);
}

int	process_map_line(char *map_line, t_params *params)
{
	params->x = 0;
	while (map_line[params->x])
	{
		if (!ft_strchr("01PEC", map_line[params->x]))
			return (1);
		params->x++;
	}
	return (0);
}

int	allocate_memory_and_check_rectangular(t_params *params)
{
	if (params->y == 0)
	{
		params->map = (char **)malloc(sizeof(char *) * (params->y + 1));
		params->x_max = params->x;
	}
	else if (params->x != params->x_max)
	{
		return (2);
	}
	return (0);
}

int	parse_map(int fd, t_params *params)
{
	char	*map_line;
	char	*temp;
	int		error_code;

	params->y = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map_line = ft_strtrim(temp, "\n");
		free(temp);
		error_code = process_map_line(map_line, params);
		if (error_code != 0)
			return (error_code);
		error_code = allocate_memory_and_check_rectangular(params);
		if (error_code != 0)
			return (error_code);
		params->map[params->y++] = map_line;
	}
	params->map[params->y] = NULL;
	return (0);
}

int	surrounded_by_walls(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->x_max)
	{
		if (params->map[0][i] != '1' || params->map[params->y - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < params->y)
	{
		if (params->map[j][0] != '1' || params->map[j][params->x_max
			- 1] != '1')
			return (0);
		j++;
	}
	return (1);
}
