/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:57:22 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/19 14:57:23 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_hex(char *str)
{
	int	res;

	res = 0;
	str += 2;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			res = res * 16 + *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			res = res * 16 + *str - 'A' + 10;
		else
			break ;
		str++;
	}
	return (res);
}
