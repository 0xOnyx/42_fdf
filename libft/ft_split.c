/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:42 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/09 22:46:48 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_separator(char c, char s)
{
	if (c == '\0' || c == s)
		return (1);
	return (0);
}

static size_t	max_len(char const *s, char c)
{
	size_t	res;
	size_t	i;
	size_t	len;

	i = 0;
	res = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (!ft_is_separator(s[i], c) && ft_is_separator(s[i + 1], c))
			res++;
		i++;
	}
	return (res);
}

static void	fill_tab(char **res, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	len;

	i = 0;
	x = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		j = 0;
		while (i <= len && ft_is_separator(s[i], c))
			i++;
		while (i + j < len && s[i + j] != '\0' && s[i + j] != c)
			j++;
		if (j > 0)
			res[x++] = ft_substr(s, (unsigned int)i, j);
		i += j;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**res;

	len = max_len(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	fill_tab(res, s, c);
	res[len] = NULL;
	return (res);
}
