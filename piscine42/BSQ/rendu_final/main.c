/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:26:36 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/05 11:59:59 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/dimensions.h"
#include "include/check_map.h"
#include "include/get_map.h"
#include "include/map_check.h"
#include "include/solve.h"

int	skip_first_line(char **map)
{
	int	i;

	i = 0;
	while (**map && **map != '\n')
	{
		i++;
		(*map)++;
	}
	i++;
	(*map)++;
	return (i);
}

void	free_map(char **map, int offset)
{
	while (offset)
	{
		(*map)--;
		offset--;
	}
	free(*map);
}

int	main(int argc, char **argv)
{
	t_square	solution;
	t_dim		map_dim;
	t_chars		chars;
	char		*map;
	int			offset;
	int			i;

	i = 1;
	if (argc == 1)
		i--;
	while (i < argc)
	{
		offset = 0;
		if (!get_map(&map, argv[i], argc))
			return (0);
		if (check_map(map))
		{
			get_characters(&chars, map);
			offset = skip_first_line(&map);
			map_dim.width = map_width(map) + 1;
			map_dim.height = map_height(map, map_dim.width - 1);
			solution = solve(map, &map_dim, &chars);
            		fill_map(solution, map, &map_dim, &chars);
			print_map(map, &map_dim);
			if (i < argc - 1)
				write(1, "\n", 1);
		}
		else
			if (i < argc - 1)
				write(1, "\n", 1);
		i++;
		free_map(&map, offset);
	}
}
