/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:45:12 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/24 20:50:17 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	if (!dest1 && !src1)
	{
		return (dest1);
	}
	else if (dest > src)
	{
		while (len--)
			dest1[len] = src1[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
