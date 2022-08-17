/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:25:18 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 00:32:59 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->map_buff = NULL;
	vars->height = 0;
	vars->width = 0;
	vars->data.img = NULL;
	vars->data.addr = NULL;
	vars->data.bits_per_pixel = 0;
	vars->data.line_length = 0;
	vars->data.endian = 0;
	vars->options.angle = ANGLE;
	vars->options.width = WIDTH;
	vars->options.height = HEIGHT;
	vars->options.screen_width = SCREEN_WIDTH;
	vars->options.screen_height = SCREEN_HEIGHT;
	vars->options.offset.x = vars->options.screen_height / 2;
	vars->options.offset.y = 20;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_init_vars(&vars);
	if (!ft_valid_arg(argc, argv)
		|| !ft_safe_file(argv[1])
		|| !ft_parse_file(argv[1], &vars)
		|| !ft_init_map(argv[1], &vars)
		|| !ft_init_mlx(&vars)
	)
	{
		ft_safe_exit(vars);
		return (1);
	}
	mlx_loop_hook(vars.mlx, ft_render_next_frame, (void *)&vars);
	mlx_loop(vars.mlx);
	ft_safe_exit(vars);
	return (0);
}
