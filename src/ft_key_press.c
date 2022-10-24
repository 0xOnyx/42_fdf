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

int	ft_mouse_exit(void *data)
{
	(void)data;
	exit(1);
	return (1);
}

int	ft_key_press(int keycode, void *data)
{
	if (keycode == 119 || keycode == 13)
		((t_vars *)data)->options.offset.y += 10;
	if (keycode == 115 || keycode == 1)
		((t_vars *)data)->options.offset.y -= 10;
	if (keycode == 97 || keycode == 0)
		((t_vars *)data)->options.offset.x += 10;
	if (keycode == 100 || keycode == 2)
		((t_vars *)data)->options.offset.x -= 10;
	if (keycode == 65451 || keycode == 52 || keycode == 20)
		((t_vars *)data)->options.width += 10;
	if (keycode == 65453 || keycode == 51 || keycode == 21)
		((t_vars *)data)->options.width -= 10;
	if (keycode == 113 || keycode == 12)
		((t_vars *)data)->options.angle += 10;
	if (keycode == 101 || keycode == 14)
		((t_vars *)data)->options.angle -= 10;
	if (keycode == 49 || keycode == 18)
		((t_vars *)data)->options.height -= 10;
	if (keycode == 50 || keycode == 19)
		((t_vars *)data)->options.height += 10;
	if (keycode == 65307 || keycode == 53)
		ft_safe_exit(*(t_vars *)data);
	return (1);
}
