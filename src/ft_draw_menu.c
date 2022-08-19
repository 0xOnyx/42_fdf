/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:12:20 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/18 21:12:21 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_create_rect(t_vars *vars, t_pos offset, t_pos width, int color)
{
	int	x;
	int	y;

	x = offset.x;
	y = offset.y;
	while (y < offset.y + width.y && y < vars->options.screen_height)
	{
		x = offset.x;
		while (x < offset.x + width.x && x < vars->options.screen_width)
		{
			ft_mlx_put_pixel(&vars->data, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_menu(t_vars *vars)
{
	int		color_base;
	int		color_text;
	t_pos	offset;
	t_pos	width;

	color_base = ft_create_trgb(0, 29, 34, 43);
	color_text = ft_create_trgb(0, 255, 255, 255);
	offset.x = vars->options.screen_width - 290;
	offset.y = 20;
	width.x = 270;
	width.y = 270;
	ft_create_rect(vars, offset, width, color_base);
	mlx_set_font(vars->mlx, vars->mlx_win, "-schumacher-clean-medium-r-normal--15-150-75-75-c-90-iso646.1991-irv");
	mlx_string_put(vars->mlx, vars->mlx_win, vars->options.screen_width - 290, 30, color_text, "MOVE => A W S D");
}
