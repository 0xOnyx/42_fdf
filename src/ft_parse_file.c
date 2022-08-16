/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:44:50 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 01:04:24 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_len_array(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
	{
		free(tab[len]);
		len++;
	}
	return (len);
}

int	ft_parse_file(char *file, t_vars *vars)
{
	int	fd;
	char	*current_line;
	char	**current_parse;

	fd = open(file, O_RDONLY);
	current_line = get_next_line(fd);
	while (current_line)
	{
		current_parse = ft_split((char const *)current_line, (char)32);
		if (!vars->width)
			vars->width = ft_len_array(current_parse)
		free(current_parse);
		free(currrent_line);
		current_line = get_next_line(fd);
		vars->height++;
	}
	close(fd);
	if (!vars->height || !vars->widht)
		return (0);
	return (1);
}
