/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:27 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/09 16:27:11 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_from_charset(char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	min;
	size_t	max;

	min = 0;
	while (ft_is_from_charset(s1[min], set) && s1[min] != '\0')
		min++;
	max = ft_strlen(s1);
	while (ft_is_from_charset(s1[max - 1], set) && max - 1 > 0)
		max--;
	res = ft_substr(s1, min, max - min);
	return (res);
}
