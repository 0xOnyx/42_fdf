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

static int	ft_sign(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

static void	ft_draw_line(t_vars *vars, t_pos pos1, t_pos pos2, int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	error[2];

	dx = ft_abs(pos2.x - pos1.x);
	dy = -ft_abs(pos2.y - pos1.y);
	sx = ft_sign(pos1.x, pos2.x);
	sy = ft_sign(pos1.y, pos2.y);
	error[0] = dx + dy;
	while (pos1.x < vars->options.screen_width
		&& pos1.y < vars->options.screen_height)
	{
		if (pos1.x >= 0 && pos1.y >= 0)
			ft_mlx_put_pixel(&vars->data,
				pos1.x,
				pos1.y, color);
		if (pos1.x == pos2.x && pos1.y == pos2.y)
			break ;
		error[1] = 2 * error[0];
		if (error[1] >= dy)
		{
			if (pos1.x == pos2.x)
				break ;
			error[0] += dy;
			pos1.x += sx;
		}
		if (error[1] <= dx)
		{
			if (pos1.y == pos2.y)
				break ;
			error[0] += dx;
			pos1.y += sy;
		}
	}
}

void	ft_draw_tile(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = ft_create_trgb(0, 102, 17, 59);
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (x + 1 < vars->width)
				ft_draw_line(vars, vars->map_pos[y][x],
					vars->map_pos[y][x + 1], color);
			if (y + 1 < vars->height)
				ft_draw_line(vars, vars->map_pos[y][x],
					vars->map_pos[y + 1][x], color);
			x++;
		}
		y++;
	}
}
