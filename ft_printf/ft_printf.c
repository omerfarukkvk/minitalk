/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:08:10 by okavak            #+#    #+#             */
/*   Updated: 2022/06/03 03:52:50 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_check(va_list args, char step)
{
	int	len;

	len = 0;
	if (step == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (step == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (step == 'p')
		len += puthex(va_arg(args, unsigned long), "0123456789abcdef", 1, 16);
	else if (step == 'd' || step == 'i')
		len += ft_printnumb(va_arg(args, int));
	else if (step == 'u')
		len += ft_printunumb(va_arg(args, unsigned));
	else if (step == 'x')
		len += puthex(va_arg(args, unsigned), "0123456789abcdef", 0, 16);
	else if (step == 'X')
		len += puthex(va_arg(args, unsigned), "0123456789ABCDEF", 0, 16);
	else if (step == '%')
		len += write(1, "%", 1);
	else
		len += write(1, &step, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_check(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
