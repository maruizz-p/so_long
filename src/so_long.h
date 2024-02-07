/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:03:34 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:52:10 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libftproyectos/libft.h"
# define WIDTH 720
# define HEIGHT 480
# define IMG_WT 34
# define IMG_HE 34
# define SIZE 34

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_coin_instance
{
	int				x;
	int				y;
}					t_coin_instance;

typedef struct s_data
{
	int				x_max;
	char			**map;
	char			**map_copy;
	int				lines;
	int				columns;
	int				coin;
	int				coin_copy;
	int				player;
	int				exit;
	int				exit_copy;
	int				movements;
	t_coin_instance	**coin_instances;
	int				coin_instances_num;
	int				cc;
	t_point			p_position;
	t_point			exit_location;
	t_point			size;
	mlx_t			*mlx;
	mlx_texture_t	*wall_tx;
	mlx_image_t		*wall_img;
	mlx_texture_t	*floor_tx;
	mlx_image_t		*floor_img;
	mlx_texture_t	*coin_tx;
	mlx_image_t		*coin_img;
	mlx_texture_t	*exit_close_tx;
	mlx_image_t		*exit_img_close;
	mlx_texture_t	*exit_open_tx;
	mlx_image_t		*exit_img_open;
	mlx_texture_t	*p_front;
	mlx_image_t		*p_img_front;
	mlx_texture_t	*p_back;
	mlx_image_t		*p_img_back;
	mlx_texture_t	*p_right;
	mlx_image_t		*p_img_right;
	mlx_texture_t	*p_left;
	mlx_image_t		*p_img_left;
}					t_data;

int					parse_map(int fd, t_data *data);
int					allocate_memory_and_check_rectangular(char *map_line,
						t_data *data);
int					process_map_line(t_data *data, char *map_line, int y);
int					main_validator(char *map_path, t_data *data);
int					mapchecker(char *mapfile);
int					main(int argc, char **argv);
int					ft_error(char *error);
int					surrounded_by_walls(t_data *data);
void				flood_fill(t_data *data, int x, int y);
int					count_objects(t_data *data);
void				freeall(t_data *data);
void				resize_wdow(int width, int height, void *param);
int					second_main(t_data *data);
void				close_game(void *param);
int					readmap(t_data *data, char *map_path);
void				p_moves(mlx_key_data_t keydata, void *param);
int					img_error(t_data *data);
int					img_window(t_data *data);
void				clean_textures(t_data *data);
void				handle_c_instance(t_data *data);
void				handle_e_location(t_data *data, int x, int y);
void				handle_p_position(t_data *data, int x, int y);

#endif