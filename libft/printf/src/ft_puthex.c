/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:47:38 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/12 16:28:46 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int option, unsigned long long nbr)
{
	char	*tab_hex;
	char	current;
	int		len;

	tab_hex = "0123456789abcdef";
	len = 0;
	if (nbr >= 16)
		len += ft_puthex(option, nbr / 16);
	nbr %= 16;
	current = tab_hex[nbr];
	if (option && current >= 'a' && current <= 'f' )
		current -= 32;
	len += ft_putchar(current);
	return (len);
}
