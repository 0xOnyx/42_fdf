/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:17:47 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 02:11:40 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

# define NAME "FDF"
# define ANGLE 30
# define WIDTH 30
# define HEIGHT 5
# define SCREEN_WIDTH 1050
# define SCREEN_HEIGHT 650

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_pos
{
	int		x;
	int		y;
	int		color;
}	t_pos;

typedef struct s_options
{
	int			angle;
	int			width;
	int			height;
	t_pos		offset;
	int			screen_width;
	int			screen_height;
}	t_options;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	int			**map_buff;
	t_pos		**map_pos;
	int			width;
	int			height;
	t_data		data;
	t_options	options;
}	t_vars;

typedef struct s_draw_line
{
	t_pos	d;
	t_pos	s;
	int		error[2];
	t_pos	start;
	t_vars	*vars;
	t_pos	pos1;
	t_pos	pos2;
}	t_draw_line;

int		ft_valid_arg(int argc, char **argv);
int		ft_safe_file(char *file);
int		ft_parse_file(char *file, t_vars *vars);
int		ft_init_map(char *file, t_vars *vars);
int		ft_init_mlx(t_vars *vars);
void	ft_safe_exit(t_vars vars);
int		ft_render_next_frame(void *vars);
int		ft_mouse_exit(void *data);
int		ft_key_press(int keycode, void *data);

void	ft_mlx_put_pixel(t_data *data, int x, int y, int color);
void	ft_mlx_put_pixel_with_pos(t_data *data,
			t_pos current, t_pos start, t_pos end);
int		ft_create_trgb(int t, int r, int g, int b);

void	ft_draw_menu(t_vars *vars);
void	ft_draw_background(t_vars *vars);
void	ft_calc_map(t_vars *vars);
void	ft_draw_tile(t_vars *vars);
void	ft_print_text(t_vars *vars);

double	ft_deg_to_rad(int deg);
double	ft_cos(int deg);
double	ft_sin(int deg);
int		ft_atoi_hex(char *str);

#endif
