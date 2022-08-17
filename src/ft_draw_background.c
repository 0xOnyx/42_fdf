/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:06:07 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 22:06:08 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_background(t_vars *vars)
{
	int	color;
	int	x;
	int	y;

	color = ft_create_trgb(0, 24, 29, 38);
	y = 0;
	while (y < vars->options.screen_height)
	{
		x = 0;
		while (x < vars->options.screen_width)
		{
			ft_mlx_put_pixel(&vars->data, x, y, color);
			x++;
		}
		y++;
	}
}
