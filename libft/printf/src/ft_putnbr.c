/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:31:33 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/12 16:08:38 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= -2147483648)
	{
		len = ft_putstr("-2147483648");
		return (len);
	}
	if (nbr < 0)
	{
		len += ft_putchar((int) '-');
		nbr *= -1;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	nbr %= 10;
	nbr += '0';
	len += ft_putchar(nbr);
	return (len);
}
