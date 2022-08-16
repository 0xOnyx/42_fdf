/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:47:02 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/15 20:42:02 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_valid_arg(int argc, char **argv)
{
	if (argc != 2 || ft_strlen(argv[1]) <= 0)
	{
		ft_putstr_fd("[ERROR]: usage ./fdf <map.fdf>\n", 2);
		return (0);
	}
	return (1);
}
