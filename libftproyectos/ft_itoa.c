/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:03:15 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/05/03 20:57:46 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_get_sign(int n)
{
	return ((n >> 31) | (!!n));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_get_sign(n);
	n *= sign;
	len = ft_num_len(n);
	if (sign < 0)
		len += 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (sign == -1)
		str[i++] = '-';
	str[len] = '\0';
	while (--len >= i)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
