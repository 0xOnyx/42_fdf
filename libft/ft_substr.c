/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:02:12 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/09 15:41:00 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len_str;

	i = 0;
	j = 0;
	len_str = ft_strlen(s);
	if (start > len_str)
		len = 0;
	else if (len >= len_str)
		len = len_str - start;
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
