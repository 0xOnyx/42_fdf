/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:07:54 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 14:07:55 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_calc_buff(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->map_pos[i]);
		i++;
	}
	free(vars->map_pos);
	vars->map_pos = NULL;
}

static int	ft_init_calc_buff(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_pos = (t_pos **)malloc(sizeof(t_pos *) * vars->height);
	while (i < vars->height)
	{
		vars->map_pos[i] = (t_pos *)malloc(sizeof(t_pos) * vars->width);
		if (!vars->map_pos[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_render_next_frame(void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	if (!ft_init_calc_buff(vars))
		return (0);
	//ft_draw_background(vars);
	//ft_calc_map(vars);
	//ft_draw_tile(vars);
	//ft_draw_menu(vars);
	mlx_string_put(vars->mlx, vars->mlx_win,
				   vars->options.screen_width - 260, 60, color_text, "USAGE")
	mlx_put_image_to_window(
		vars->mlx,
		vars->mlx_win,
		vars->data.img,
		0, 0);
	ft_free_calc_buff(vars);
	return (1);
}
