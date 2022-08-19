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

static int	ft_calc_draw_line(t_draw_line *data)
{
	if (data->pos1.x >= 0 && data->pos1.y >= 0)
		ft_mlx_put_pixel_with_pos(&(data->vars->data),
			data->pos1, data->start, data->pos2);
	if (data->pos1.x == data->pos2.x && data->pos1.y == data->pos2.y)
		return (0);
	data->error[1] = 2 * data->error[0];
	if (data->error[1] >= data->d.y)
	{
		if (data->pos1.x == data->pos2.x)
			return (0);
		data->error[0] += data->d.y;
		data->pos1.x += data->s.x;
	}
	if (data->error[1] <= data->d.x)
	{
		if (data->pos1.y == data->pos2.y)
			return (0);
		data->error[0] += data->d.x;
		data->pos1.y += data->s.y;
	}
	return (1);
}

static void	ft_draw_line(t_vars *vars, t_pos pos1, t_pos pos2)
{
	t_draw_line	data;

	data.start = pos1;
	data.d.x = ft_abs(pos2.x - pos1.x);
	data.d.y = -ft_abs(pos2.y - pos1.y);
	data.s.x = ft_sign(pos1.x, pos2.x);
	data.s.y = ft_sign(pos1.y, pos2.y);
	data.error[0] = data.d.x + data.d.y;
	data.vars = vars;
	data.pos1 = pos1;
	data.pos2 = pos2;
	while (data.pos1.x < vars->options.screen_width
		&& data.pos1.y < vars->options.screen_height)
	{
		if (!ft_calc_draw_line(&data))
			break ;
	}
}

void	ft_draw_tile(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (x + 1 < vars->width)
				ft_draw_line(vars, vars->map_pos[y][x],
					vars->map_pos[y][x + 1]);
			if (y + 1 < vars->height)
				ft_draw_line(vars, vars->map_pos[y][x],
					vars->map_pos[y + 1][x]);
			x++;
		}
		y++;
	}
}
