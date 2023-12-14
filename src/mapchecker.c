/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:55:09 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/12/07 21:48:03 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapchecker(char *mapfile)
{
	char	*format;

	format = ft_strrchr(mapfile, '.');
	if (format != NULL)
	{
		if (ft_strncmp(format, ".ber", 4) == 0)
			return (1);
	}
	return (0);
}
