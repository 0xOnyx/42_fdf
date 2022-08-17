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
	dest += y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int *)dest = color;
}

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
