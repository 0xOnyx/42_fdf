/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:25:22 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/08 14:13:25 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*current;

	current = (unsigned char *)s;
	i = 0;
	while (i < n)
	{	
		if (current[i] == (unsigned char)c)
			return (current + i);
		i++;
	}
	return (NULL);
}
