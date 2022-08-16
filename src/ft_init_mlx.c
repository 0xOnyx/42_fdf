/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:06:22 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 02:21:37 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_mlx(t_map *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
		vars->options.screen_width,
		vars->options.screen_height);
	vars->mlx.data.img = mlx_new_image(vars->mlx
		vars->options.screen_width,
		vars->options.screen_height);
	vars->mlx.data.addr = mlx_get_data_addr(vars->mlx.data.img,
		&vars->mlx.data.bits_per_pixel,
		&vars->mlx.data.line_length,
		&vars->mlx.data.endian);
	mlx_hook(vars->mlx_win, 2, 1L<<0, ft_key_press, (void *)vars));
	return (1);
}
