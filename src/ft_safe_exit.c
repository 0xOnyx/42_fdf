/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:35:31 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 02:47:23 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static ft_free_map(char **buff, t_vars vars)
{
	int	i;

	i = 0;
	while(i < vars.height)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

void	ft_safe_exit(t_vars vars)
{
	if (vars.mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars.map_buff)
		ft_free_map(vars.map_buff, vars);
	if (vars.data.img)
		free(vars.data.img);
}
