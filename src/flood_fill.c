/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:46:49 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/01/24 15:26:31 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->x_max || y < 0 || y >= data->size.y
		|| data->map_copy[y][x] != '0')
	{
		return ;
	}
	data->map_copy[y][x] = '*';
	if (data->map_copy[y][x] == 'C')
		data->coin_copy++;
	if (data->map_copy[y][x] == 'E')
	{
		data->exit_copy++;
		data->exit_location.x = x;
		data->exit_location.y = y;
	}
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
