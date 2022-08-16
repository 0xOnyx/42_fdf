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

int	ft_render_next_frame(void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	if(vars)
		return (1);
	return (1);
}