/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:13:56 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/26 13:47:24 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s1;

	i = 0;
	s1 = (const unsigned char *)s;
	while (i < n && s1[i] != (unsigned char)c)
	{
		i++;
	}
	if (i == n)
	{
		return (NULL);
	}
	else
	{
		return ((void *)&s1[i]);
	}
}
