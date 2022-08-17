/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:46:08 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/17 11:46:09 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_deg_to_rad(int deg)
{
	return (deg * (M_PI / 180));
}

double	ft_cos(int deg)
{
	double	rad;

	rad = ft_deg_to_rad(deg);
	return (cos(rad));
}

double	ft_sin(int deg)
{
	double rad;

	rad = ft_deg_to_rad(deg);
	return (sin(rad));
}
