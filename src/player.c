/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:11:22 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/01 16:19:43 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	o_move(t_data *data, int x, int y, mlx_texture_t *texture)
{
	mlx_delete_image(data->mlx, data->p_img_front);
	data->p_img_front = mlx_texture_to_image(data->mlx, texture);
	if (data->map[data->p_position.y][data->p_position.x] != 'E')
		data->map[data->p_position.y][data->p_position.x] = '0';
	data->map[y][x] = 'P';
	if (data->map[data->p_position.y][data->p_position.x] == 'E')
		mlx_image_to_window(data->mlx, data->exit_img_close, data->p_position.x
			* SIZE, data->p_position.y * SIZE);
	data->p_position.x = x;
	data->p_position.y = y;
	mlx_image_to_window(data->mlx, data->p_img_front, data->p_position.x * SIZE,
		data->p_position.y * SIZE);
	data->movements++;
}

static void	e_move(t_data *data, int x, int y, mlx_texture_t *texture)
{
	mlx_delete_image(data->mlx, data->p_img_front);
	data->p_img_front = mlx_texture_to_image(data->mlx, texture);
	data->map[data->p_position.y][data->p_position.x] = '0';
	if (data->map[data->p_position.y][data->p_position.x] == 'E')
		mlx_image_to_window(data->mlx, data->exit_img_close, data->p_position.x
			* SIZE, data->p_position.y * SIZE);
	data->p_position.x = x;
	data->p_position.y = y;
	mlx_image_to_window(data->mlx, data->p_img_front, data->p_position.x * SIZE,
		data->p_position.y * SIZE);
	data->movements++;
	if (data->coin == data->coin_instances_num)
	{
		ft_printf("YOU WIN!\n");
		exit(0);
	}
}

static void	c_move(t_data *data, int x, int y, mlx_texture_t *texture)
{
	int	i;

	o_move(data, x, y, texture);
	i = 0;
	while (data->coin_instances[i]->x != x || data->coin_instances[i]->y != y)
		++i;
	data->coin_img->instances[i].enabled = false;
	data->coin++;
	data->movements++;
	if (data->coin == data->coin_instances_num)
	{
		mlx_image_to_window(data->mlx, data->exit_img_open,
			data->exit_location.x * SIZE, data->exit_location.y * SIZE);
	}
}

static void	presskey(t_data *data, int x, int y, void *img)
{
	if (data->map[y][x] == 'C')
	{
		c_move(data, x, y, img);
		ft_printf("Movements: %d\n", data->movements);
		ft_printf("Coins: %d\n", data->coin);
	}
	else if (data->map[y][x] == 'E' && data->coin == data->coin_instances_num)
	{
		ft_printf("YOU WIN!\n");
		close_game(data);
	}
	else if (data->map[y][x] == 'E')
	{
		e_move(data, x, y, img);
		ft_printf("Movements: %d\n", data->movements);
	}
	else if (data->map[y][x] == '0')
	{
		o_move(data, x, y, img);
		ft_printf("Movements: %d\n", data->movements);
	}
}

void	p_moves(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(data);
	if (keydata.action == MLX_PRESS)
		if (keydata.key == MLX_KEY_A)
			presskey(data, data->p_position.x - 1, data->p_position.y,
				data->p_left);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		presskey(data, data->p_position.x, data->p_position.y + 1,
			data->p_front);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		presskey(data, data->p_position.x + 1, data->p_position.y,
			data->p_right);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		presskey(data, data->p_position.x, data->p_position.y - 1,
			data->p_back);
}
