/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:18:41 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/23 17:22:15 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format(const char *str, va_list list)
{
	int	val;

	val = 0;
	if (*str == 'c')
		val += ft_putchar(va_arg(list, int));
	else if (*str == 's')
		val += ft_putstr(va_arg(list, char *));
	else if (*str == 'p')
		val += ft_printptr(va_arg(list, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		val += ft_printdec(va_arg(list, int));
	else if (*str == 'u')
		val += ft_unsigned(va_arg(list, unsigned int));
	else if (*str == 'x')
		val += ft_printhexa(va_arg(list, unsigned int), 'x');
	else if (*str == 'X')
		val += ft_printhexa(va_arg(list, unsigned int), 'X');
	else if (*str == '%')
		val += ft_putchar('%');
	return (val);
}

static int	check_format(const char *str, va_list list)
{
	int	val;

	val = 0;
	while (*str)
	{
		if (*str != '%')
		{
			val += ft_putchar(*str);
			str++;
		}
		else
		{
			str++;
			val += handle_format(str, list);
			str++;
		}
	}
	return (val);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		val;

	val = 0;
	va_start(list, str);
	val = check_format(str, list);
	va_end(list);
	return (val);
}
/* 
int	main(void)
{
	ft_printf("%s, hola klk")
} */
