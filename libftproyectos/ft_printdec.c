/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:51:05 by maruiz-p          #+#    #+#             */
/*   Updated: 2024/01/19 17:31:10 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

static int	ft_dcount(long int n)
{
	int	counter;

	counter = 0;
	while (n >= 10)
	{
		counter++;
		n /= 10;
	}
	return (counter + 1);
}

int	ft_printdec(long int n)
{
	long int	temp;

	temp = 0;
	ft_putnbr(n);
	if (n >= 0)
		return (ft_dcount(n));
	temp = (long int)n * (-1);
	return (ft_dcount(temp) + 1);
}
