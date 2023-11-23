/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:52:40 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/04/27 11:42:30 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s) + 1;
	new_s = malloc(len);
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_memcpy(new_s, s, len);
	return (new_s);
}
