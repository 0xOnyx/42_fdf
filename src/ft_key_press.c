/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:15:12 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/16 14:15:14 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mouse_press(int button, int x, int y, void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	printf("value => %d %d %d\n", button, x, y);
	if (vars)
		return (0);
	return (1);
}

int	ft_mouse_move(int x, int y, void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	printf("value => %d %d\n", x, y);
	if (vars)
		return (0);
	return (1);
}

int	ft_mouse_release(int button, int x, int y, void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	printf("value => %d %d %d\n", button, x, y);
	if (vars)
		return (0);
	return (1);
}

int	ft_mouse_exit(void *data)
{
	ft_safe_exit(*(t_vars *)data);
	return (1);
}

int	ft_key_press(int keycode, void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	if (keycode == 119)
		vars->options.offset.y += 10;
	if (keycode == 115)
		vars->options.offset.y -= 10;
	if (keycode == 97)
		vars->options.offset.x += 10;
	if (keycode == 100)
		vars->options.offset.x -= 10;
	if (keycode == 65451)
		vars->options.width += 10;
	if (keycode == 65453)
		vars->options.width -= 10;
	if (keycode == 113)
		vars->options.angle += 10;
	if (keycode == 101)
		vars->options.angle -= 10;
	if (keycode == 49)
		vars->options.height -= 10;
	if (keycode == 50)
		vars->options.height += 10;
	return (1);
}
