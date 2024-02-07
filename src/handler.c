/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:29:48 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:50:20 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_p_position(t_data *data, int x, int y)
{
	if (data->p_position.x || data->p_position.y)
		ft_error("There's more than one player");
	data->p_position.x = x;
	data->p_position.y = y;
}

void	handle_e_location(t_data *data, int x, int y)
{
	if (data->exit_location.x || data->exit_location.y)
		ft_error("There's more than one exit");
	data->exit_location.x = x;
	data->exit_location.y = y;
}

void	handle_c_instance(t_data *data)
{
	++(data->coin_instances_num);
}
