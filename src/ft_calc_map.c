/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:11:25 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 22:11:26 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_calc_h(t_vars vars, int x, int y)
{
	double	res;

	x *= vars.options.width;
	y *= vars.options.width;
	res = (x - y) * ft_cos(vars.options.angle);
	res += vars.options.offset.x;
	return ((int)res);
}

static int	ft_calc_v(t_vars vars, int x, int y, int z)
{
	double	res;

	x *= vars.options.width;
	y *= vars.options.width;
	z *= vars.options.height;
	res = (-z + (x + y) * ft_sin(vars.options.angle));
	res += vars.options.offset.y;
	return ((int)res);
}

void	ft_calc_map(t_vars *vars)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			vars->map_pos[y][x].x = ft_calc_h(*vars, x, y);
			vars->map_pos[y][x].y = ft_calc_v(
					*vars, x, y,
					vars->map_buff[y][x]);
			if (vars->map_buff[y][x] > 0)
				vars->map_pos[y][x].color = ft_create_trgb(0, 198, 185, 205);
			else
				vars->map_pos[y][x].color = ft_create_trgb(0, 102, 17, 59);
			x++;
		}
		y++;
	}
}
