/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:50:21 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/08 22:14:06 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	return (res);
}
