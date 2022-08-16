/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:38:39 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/08 15:29:33 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		res;
	int		neg;
	char	*current;

	res = 0;
	neg = 1;
	current = (char *)nptr;
	while (*current != '\0'
		&& ft_isspace((int)*current))
		current++;
	if (*current == '-' || *current == '+')
	{
		if (*current == '-')
			neg = -1;
		current++;
	}
	while (*current != '\0' && ft_isdigit((int)*current))
	{
		res *= 10;
		res += *current - 48;
		current++;
	}
	return (res * neg);
}
