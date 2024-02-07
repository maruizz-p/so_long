/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:03:24 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/07 11:55:40 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_game(t_data *data)
{
	data->map = NULL;
	data->map_copy = NULL;
	data->lines = 0;
	data->columns = 0;
	data->coin = 0;
	data->coin_copy = 0;
	data->player = 0;
	data->exit = 0;
	data->exit_copy = 0;
	data->movements = 0;
	data->size.y = 0;
	data->size.x = 0;
	data->x_max = 0;
}

static int	initialize_img(t_data *data)
{
	data->exit_close_tx = mlx_load_png("imgs/puerta_cerrada.png");
	data->exit_open_tx = mlx_load_png("imgs/puerta_abierta.png");
	data->floor_tx = mlx_load_png("imgs/floor.png");
	data->wall_tx = mlx_load_png("imgs/walls.png");
	data->coin_tx = mlx_load_png("imgs/colect.png");
	data->p_front = mlx_load_png("imgs/gengar_abajo.png");
	data->p_back = mlx_load_png("imgs/gengar_arriba.png");
	data->p_left = mlx_load_png("imgs/gengar_izq.png");
	data->p_right = mlx_load_png("imgs/gengar_drch.png");
	data->exit_img_close = mlx_texture_to_image(data->mlx, data->exit_close_tx);
	data->exit_img_open = mlx_texture_to_image(data->mlx, data->exit_open_tx);
	data->floor_img = mlx_texture_to_image(data->mlx, data->floor_tx);
	data->wall_img = mlx_texture_to_image(data->mlx, data->wall_tx);
	data->coin_img = mlx_texture_to_image(data->mlx, data->coin_tx);
	data->p_img_front = mlx_texture_to_image(data->mlx, data->p_front);
	if (img_error(data) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	close_game(void *param)
{
	t_data	*data;

	data = param;
	mlx_close_window(data->mlx);
	freeall(data);
}

int	second_main(t_data *data)
{
	if (img_window(data) == 1)
		return (EXIT_FAILURE);
	mlx_key_hook(data->mlx, &p_moves, data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf("There's no map to read\n"), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	initialize_game(data);
	if (main_validator(argv[1], data) == 1)
		return (freeall(data), EXIT_FAILURE);
	data->mlx = mlx_init(WIDTH, HEIGHT, "SO_LONG", false);
	if (!data->mlx)
		return (freeall(data), EXIT_FAILURE);
	if (initialize_img(data) == 1)
		return (freeall(data), EXIT_FAILURE);
	if (second_main(data) == 1)
		return (freeall(data), EXIT_FAILURE);
	mlx_resize_hook(data->mlx, &resize_wdow, NULL);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (freeall(data), EXIT_SUCCESS);
}
