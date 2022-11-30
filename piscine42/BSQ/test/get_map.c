/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:03:52 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 12:06:43 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_map.h"

int	map_error_open(void)
{
	write(1, "Error\n", 11);
	return (0);
}

int	map_size(char *file, int ac)
{
	int		size_file;
	char	*c_temp;
	int		fd;
	int		end_read_file;

	size_file = 0;
	end_read_file = 1;
	c_temp = malloc(sizeof(char) * 1000000);
	if (ac != 1)
		fd = open(file, O_RDONLY, 0);
	else
		fd = 0;
	if (fd == -1)
		return (map_error_open());
	while (end_read_file != 0)
	{
		end_read_file = read(fd, c_temp, 1000000);
		size_file += end_read_file;
	}
	close(fd);
	free(c_temp);
	return (size_file);
}

int	get_map(char **buf, char *file, int ac)
{
	int		size_file;
	int		fd;

	if (map_size(file, ac) == 0)
		return (0);
	size_file = map_size(file, ac);
	*buf = (char *)malloc(size_file);
	if (*buf == NULL)
		return (0);
	if (ac != 1)
		fd = open(file, O_RDONLY, 0);
	else
		fd = 0;
	if (fd == -1)
	{
		free(buf);
		return (map_error_open());
	}
	read(fd, *buf, (size_file - 1));
	close(fd);
	return (1);
}
