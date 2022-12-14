/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:04:56 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 01:56:22 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_parse(char **current_parse, t_vars *vars, int current_pos)
{
	int	i;

	vars->map_buff[current_pos] = (int *)malloc(sizeof(int) * vars->width);
	if (!vars->map_buff)
		return ;
	i = 0;
	while (i < vars->width)
	{
		if (ft_strlen(current_parse[i]) >= 2 && current_parse[i][1] == 'x')
			vars->map_buff[current_pos][i] = ft_atoi_hex(current_parse[i]);
		else
			vars->map_buff[current_pos][i] = ft_atoi(current_parse[i]);
		free(current_parse[i]);
		i++;
	}
}

int	ft_init_map(char *file, t_vars *vars)
{
	int		fd;
	int		current_pos;
	char	*current_line;
	char	**current_parse;
	char	*buff_gnl;

	current_pos = 0;
	buff_gnl = NULL;
	fd = open(file, O_RDONLY);
	current_line = get_next_line(fd, &buff_gnl);
	vars->map_buff = (int **)malloc(sizeof(int *) * vars->height);
	while (current_line)
	{
		current_parse = ft_split((char const *)current_line, (char)32);
		ft_parse(current_parse, vars, current_pos);
		free(current_parse);
		free(current_line);
		current_line = get_next_line(fd, &buff_gnl);
		current_pos++;
	}
	free(buff_gnl);
	close(fd);
	return (1);
}
