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

static void	ft_print_text(t_vars *vars)
{
	int		color_text;

	color_text = ft_create_trgb(0, 255, 255, 255);
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 260, 60, color_text, "USAGE");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 240, 100, color_text, "MOVE");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 140, 100, color_text, "A W S D");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 240, 130, color_text, "ANGLE");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 140, 130, color_text, "Q E");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 240, 160, color_text, "ZOOM");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 140, 160, color_text, "3 4");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 240, 190, color_text, "HEIGHT");
	mlx_string_put(vars->mlx, vars->mlx_win,
		vars->options.screen_width - 140, 190, color_text, "1 2");
}

void	ft_draw_menu(t_vars *vars)
{
	int		color_base;
	t_pos	offset;
	t_pos	width;

	color_base = ft_create_trgb(0, 29, 34, 43);
	offset.x = vars->options.screen_width - 290;
	offset.y = 20;
	width.x = 270;
	width.y = 240;
	ft_create_rect(vars, offset, width, color_base);
	ft_print_text(vars);
}
