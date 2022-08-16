/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:16:52 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/12 16:47:49 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list va, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar((int)va_arg(va, int));
	else if (format == 's')
		len = ft_putstr((char *)va_arg(va, char *));
	else if (format == 'p')
		len = ft_putptr((unsigned long long)va_arg(va, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_putnbr((int)va_arg(va, int));
	else if (format == 'u')
		len = ft_putnbr_unsigned((unsigned long long)va_arg(va, unsigned int));
	else if (format == 'x')
		len = ft_puthex(0, (unsigned long long)va_arg(va, unsigned int));
	else if (format == 'X')
		len = ft_puthex(1, (unsigned long long)va_arg(va, unsigned int));
	else if (format == '%')
		len = ft_putchar((int) '%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	i;
	int		len_write;

	va_start(va, format);
	i = 0;
	len_write = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len_write += ft_print_format(va, format[i + 1]);
			i++;
		}
		else
			len_write += ft_putchar(format[i]);
		i++;
	}
	va_end(va);
	return (len_write);
}
