/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:12:08 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 22:12:09 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_tile(t_vars *vars)
{
	int x;
	int y;
	int	color;

	y = 50;
	x = 50;
	color = ft_create_trgb(0, 102, 17, 59);
	ft_mlx_put_pixel(&vars->data, 0, 0, color);
	while (y < vars->options.screen_height)
	{
		ft_mlx_put_pixel(&vars->data, x, y, color);
		y++;
	}
}
