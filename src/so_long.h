/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:03:34 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/12/13 14:11:06 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libftproyectos/libft.h"

int			mapchecker(char *mapfile);

typedef struct s_params
{
	int		x;
	int		y;
	int		x_max;
	char	**map;
	char	**map_copy;
}			t_params;

int			parse_map(int fd, t_params *params);
int			allocate_memory_and_check_rectangular(t_params *params);
int			process_map_line(char *map_line, t_params *params);
void		main_validator(char *map_path, t_params *params);
int			mapchecker(char *mapfile);
int			main(int argc, char **argv);
void		ft_error(char *error);
int			surrounded_by_walls(t_params *params);

#endif