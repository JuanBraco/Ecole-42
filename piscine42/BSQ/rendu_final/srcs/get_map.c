/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:36:06 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/05 20:57:03 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../include/get_map.h"
#include "../include/gen_fct.h"

int	map_error_open(void)
{
	write(1, "map error\n", 11);
	return (0);
}

int	ft_realloc(char **buf, int size_buf)
{
	char	*tmp_string;
	int		i;

	tmp_string = ft_strdup(*buf);
	if (!tmp_string)
	{
		free(*buf);
		return (0);
	}
	free(*buf);
	*buf = malloc(size_buf + 1);
	if (*buf == NULL)
		return (0);
	i = 0;
	while (tmp_string[i])
	{
		(*buf)[i] = tmp_string[i];
		i++;
	}
	free(tmp_string);
	(*buf)[i] = '\0';
	return (1);
}

int	open_file(char *file, int argc)
{
	int	fd;

	fd = 0;
	if (argc != 1)
		fd = open(file, O_RDONLY, 0);
	else
		fd = 0;
	if (fd == -1)
	{
		write(1, "error open file\n", 11);
		return (-1);
	}
	return (fd);
}

int	read_files(char **buf, int fd)
{
	int		read_bites;
	int		size_buf;
	char	*temp_buf;

	read_bites = 2048;
	size_buf = 2048;
	temp_buf = malloc(2048);
	if (!temp_buf)
	{
		free(*buf);
		return (0);
	}
	while (read_bites == 2048)
	{
		read_bites = read(fd, temp_buf, 2048);
		size_buf += 2048;
		if (!ft_realloc(buf, size_buf))
			return (0);
		ft_strcat(*buf, temp_buf);
		empty_str(temp_buf);
	}
	free(temp_buf);
	return (1);
}

int	get_map(char **buf, char *file, int argc)
{
	int	fd;

	if (open_file(file, argc) == -1)
		return (0);
	else
		fd = open_file(file, argc);
	*buf = malloc(2048);
	if (!*buf)
		return (0);
	**buf = 0;
	if (!read_files(buf, fd))
		return (0);
	return (1);
}
