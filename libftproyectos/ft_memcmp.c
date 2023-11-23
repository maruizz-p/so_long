/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:48:09 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/26 17:11:38 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;
	int		result;

	p1 = (char *)s1;
	p2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		result = ft_strncmp(p1 + i, p2 + i, 1);
		if (result != 0)
		{
			return (result);
		}
		i++;
	}
	return (0);
}
