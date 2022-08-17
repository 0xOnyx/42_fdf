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

int	ft_init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(
			vars->mlx,
			vars->options.screen_width,
			vars->options.screen_height,
			NAME); 
	vars->data.img = mlx_new_image(
			vars->mlx,
			vars->options.screen_width,
			vars->options.screen_height);
	vars->data.addr = mlx_get_data_addr(
			vars->data.img,
			&vars->data.bits_per_pixel,
			&vars->data.line_length,
			&vars->data.endian);
	mlx_hook(vars->mlx_win, 4, 0, ft_mouse_press, (void *)vars);
	mlx_hook(vars->mlx_win, 5, 0, ft_mouse_release, (void *)vars);
	mlx_hook(vars->mlx_win, 6, 0, ft_mouse_move, (void *)vars);
	mlx_hook(vars->mlx_win, 2, 0, ft_key_press, (void *)vars);
	mlx_hook(vars->mlx_win, 17, 0, ft_mouse_exit, (void *)vars);
	return (1);
}
