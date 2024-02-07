/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:10:45 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/01/08 16:22:13 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_objects(t_data *data)
{
	int	i;
	int	j;

	j = data->lines;
	while (--j > 0)
	{
		i = -1;
		while (data->map[j][++i] != '\0')
		{
			if (data->map[j][i] == 'C')
				data->coin++;
			else if (data->map[j][i] == 'P')
			{
				data->player++;
				data->p_position.x = i;
				data->p_position.y = j;
			}
			else if (data->map[j][i] == 'E')
				data->exit++;
		}
	}
	if (data->coin == 0 || data->player != 1 || data->exit != 1)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
