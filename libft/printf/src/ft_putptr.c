/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:49:47 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/12 16:53:30 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += ft_putstr("(nil)");
	else
	{
		len = ft_putstr("0x");
		len += ft_puthex(0, ptr);
	}
	return (len);
}
