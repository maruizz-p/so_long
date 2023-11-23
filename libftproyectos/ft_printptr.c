/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:31:11 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/23 17:23:09 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	counter += ft_putstr("0x");
	counter += ft_printhexa(ptr, 'x');
	return (counter);
}
