/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:25:50 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 21:25:51 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr;
	if (!dest)
		return ;
	dest += y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int *)dest = color;
}

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static double	ft_get_percent(int current, int start, int end)
{
	double	distance;
	double	placement;

	distance = end - start;
	placement = end - current;
	if (distance == 0)
		return (1);
	return (placement / distance);
}

int	ft_get_pourcent_value(double percent, int start_color, int end_color)
{
	int	color;

	color = percent * start_color;
	color += (1 - percent) * end_color;
	return (color);
}

void	ft_mlx_put_pixel_with_pos(t_data *data,
			t_pos current, t_pos start, t_pos end)
{
	int		color_start;
	int		color_end;
	int		color_calc;
	double	percent;

	color_start = ft_create_trgb(0, 102, 17, 59);
	color_end = ft_create_trgb(0, 255, 255, 255);
	if (start.x - end.x > start.y - end.y)
		percent = ft_get_percent(current.x, start.x, end.x);
	else
		percent = ft_get_percent(current.y, start.y, end.y);
	color_calc = ft_create_trgb(
			ft_get_pourcent_value(percent,
				color_start >> 24 & 0xFF, color_end >> 24 & 0xFF),
			ft_get_pourcent_value(percent,
				color_start >> 16 & 0xFF, color_end >> 16 & 0xFF),
			ft_get_pourcent_value(percent,
				color_start >> 8 & 0xFF, color_end >> 16 & 0xFF),
			ft_get_pourcent_value(percent,
				color_start & 0xFF, color_end & 0xFF));
	ft_mlx_put_pixel(data, current.x, current.y, color_calc);
}
