/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:03:24 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/12/13 15:06:05 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 2)
		return (ft_printf("Numero de argumentos incorrecto\n"), 1);
	if (validator(argv[1], &params) == 0)
		return (ft_printf("Formato de archivo incorrecto\n"), 1);
}
