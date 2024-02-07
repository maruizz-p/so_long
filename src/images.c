/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:17:11 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/01/28 19:28:51 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_error(t_data *data)
{
	if (!data->exit_img_close || !data->exit_img_open || !data->floor_img
		|| !data->wall_img || !data->coin_img || !data->p_img_front
		|| !data->floor_tx || !data->wall_tx || !data->p_back || !data->p_front
		|| !data->p_left || !data->p_right || !data->exit_close_tx
		|| !data->exit_open_tx || !data->coin_tx)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	clean_textures(t_data *data)
{
	mlx_delete_texture(data->exit_close_tx);
	mlx_delete_texture(data->exit_open_tx);
	mlx_delete_texture(data->floor_tx);
	mlx_delete_texture(data->wall_tx);
	mlx_delete_texture(data->coin_tx);
	mlx_delete_texture(data->p_front);
	mlx_delete_texture(data->p_back);
	mlx_delete_texture(data->p_left);
	mlx_delete_texture(data->p_right);
}

static int	img_window3(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		if (mlx_image_to_window(data->mlx, data->floor_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(data->mlx, data->coin_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
		data->coin_instances[data->cc] = malloc(sizeof(t_coin_instance));
		data->coin_instances[data->cc]->x = j;
		data->coin_instances[data->cc++]->y = i;
	}
	if (data->map[i][j] == 'E')
	{
		if (mlx_image_to_window(data->mlx, data->floor_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(data->mlx, data->exit_img_close, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	img_window2(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
	{
		if (mlx_image_to_window(data->mlx, data->floor_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(data->mlx, data->wall_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
	}
	if (data->map[i][j] == '0')
		if (mlx_image_to_window(data->mlx, data->floor_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
	if (data->map[i][j] == 'P')
	{
		if (mlx_image_to_window(data->mlx, data->floor_img, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(data->mlx, data->p_img_front, j * SIZE, i
				* SIZE) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	img_window(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->columns = ft_strlen(data->map[0]);
	i = -1;
	while (++i < data->lines)
	{
		j = -1;
		while (++j < data->columns)
		{
			if (img_window2(data, i, j) == 1)
				return (EXIT_FAILURE);
			if (img_window3(data, i, j) == 1)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
