/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:09:15 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/25 20:11:38 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dsize)
	{
		i++;
	}
	while (src[j] && i + j + 1 < dsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
