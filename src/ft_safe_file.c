/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:33:15 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/15 20:44:32 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_safe_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, &c, 1) < 0)
	{
		perror("[ERROR]");
		if (fd > 0)
			close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
