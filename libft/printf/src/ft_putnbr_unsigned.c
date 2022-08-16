/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:31:33 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/12 16:09:16 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len += ft_putnbr_unsigned(nbr / 10);
	nbr %= 10;
	nbr += '0';
	len += ft_putchar(nbr);
	return (len);
}
