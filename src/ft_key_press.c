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

int		ft_key_press(int keycode, void *data)
{
	t_vars	*vars;
	
	vars = (t_vars *)data;
	if (keycode == 53)
		ft_safe_exit(*vars);

	return (1);
}
