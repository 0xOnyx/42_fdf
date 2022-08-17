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

static void	ft_free_map(int **buff, t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.height)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

void	ft_safe_exit(t_vars vars)
{
	if (vars.mlx && vars.mlx_win)
		mlx_destroy_window(vars.mlx, vars.mlx_win);
	if (vars.mlx && vars.data.img)
		mlx_destroy_image(vars.mlx, vars.data.img);
	if (vars.map_buff)
		ft_free_map(vars.map_buff, vars);
}
