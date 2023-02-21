/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:52:38 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 12:13:01 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_values(char *line, t_fdf *fdf)
{
	int	len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (*line != ' ' && *line && *line != '\n')
				line += 1;
		}
		else if (*line != ' ' && *line != '-' && *line != '\n')
			ft_error("Invalid characters or read error...!!!", 1, fdf);
		else
			line += 1;
	}
	return (len);
}

static void	count_lines(t_fdf *fdf, char *map_file)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	rows = 0;
	cols = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening", 1, fdf);
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\0')
			break ;
		len = count_values(line, fdf);
		ft_check(&cols, &rows, len, fdf);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		ft_error("Error closing", 1, fdf);
	fdf->map.len_col = cols;
	fdf->map.len_row = rows;
}

static void	get_values(t_fdf *fdf, int x, int y, char *line)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	if (tab)
	{
		i = 0;
		while (tab[i] && (x != fdf->map.len_col))
		{
			ft_atoi_bis(tab[i++], fdf, x, y);
			x += 1;
		}
		ft_free((void **)tab);
		free(tab);
	}
}

void	ft_read_line(t_fdf *fdf, int fd)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line && y != fdf->map.len_row)
	{
		fdf->map.val[y] = (int *)malloc(sizeof(int) * fdf->map.len_col);
		if (!fdf->map.val[y])
			ft_error("Memory Allocation failed!!!", 1, fdf);
		fdf->map.color[y] = (int *)malloc(sizeof(int) * fdf->map.len_col);
		if (!fdf->map.color[y])
			ft_error("Memory Allocation failed!!!", 1, fdf);
		get_values(fdf, x, y, line);
		x = 0;
		y++;
		free(line);
		line = get_next_line(fd);
	}
}

void	ft_read_map(char *map_file, t_fdf *fdf)
{
	int		fd;

	count_lines(fdf, map_file);
	fd = ft_open(map_file, fdf);
	fdf->map.val = (int **)malloc(sizeof(int *) * fdf->map.len_row);
	fdf->map.color = (int **)malloc(sizeof(int *) * fdf->map.len_row);
	if (!fdf->map.val)
		ft_error("Memory Allocation failed!!!", 1, fdf);
	if (!fdf->map.color)
		ft_error("Memory Allocation failed!!!", 1, fdf);
	ft_read_line(fdf, fd);
	if (close(fd) < 0)
		ft_error("Error closing", 1, fdf);
}
