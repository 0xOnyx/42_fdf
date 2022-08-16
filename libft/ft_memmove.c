/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:17:57 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/08 17:09:29 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	if (dest_char > src_char)
	{
		while (i++ < n)
			dest_char[n - i] = src_char[n - i];
	}
	else
	{
		while (i++ < n)
			dest_char[i - 1] = src_char[i - 1];
	}
	return (dest);
}
