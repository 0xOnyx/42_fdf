/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:46:35 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/08 17:14:22 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*current;

	current = (char *)s + ft_strlen((char *)s);
	while (*current != (char)c)
	{
		if (current == s)
			return (NULL);
		current--;
	}
	return (current);
}
