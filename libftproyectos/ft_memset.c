/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:38:36 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/24 17:26:03 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t num)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = b;
	while (i < num)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
