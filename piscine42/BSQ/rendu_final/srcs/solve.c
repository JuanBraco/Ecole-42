/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:39:36 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/05 11:56:17 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../include/dimensions.h"
#include "../include/solve.h"
#include "../include/map_check.h"

int	is_ok(t_square square, char *map, t_dim *map_dim, t_chars *chars)
{
	int	row;
	int	col;

	row = square.y;
	col = square.x;
	if (col + square.size > map_dim->width
		|| row + square.size > map_dim->height)
		return (0);
	while (row < square.size + square.y)
	{
		col = square.x;
		while (col < square.size + square.x)
		{
			if (map[col + (row * map_dim->width)] == chars->obstacle
				|| map[col + (row * map_dim->width)] == '\n')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	init_square(t_square *square)
{
	square->size = 0;
	square->x = 0;
	square->y = 0;
}

t_square	solve(char *map, t_dim *map_dim, t_chars *chars)
{
	t_square	square;
	t_square	solution;

	init_square(&square);
	init_square(&solution);
	while (square.y < map_dim->height - square.size)
	{
		square.x = 0;
		while (square.x < map_dim->width - square.size)
		{
			if (is_ok(square, map, map_dim, chars))
			{
				while (is_ok(square, map, map_dim, chars))
					square.size++;
				square.size--;
			}
			if (solution.size < square.size)
				solution = square;
			square.x++;
		}
		square.y++;
	}
	return (solution);
}

void	fill_map(t_square square, char *map, t_dim *map_dim, t_chars *chars)
{
	int	row;
	int	col;

	row = square.y;
	while (row < square.size + square.y)
	{
		col = square.x;
		while (col < square.size + square.x)
		{
			map[col + (row * map_dim->width)] = chars->plein;
			col++;
		}
		row++;
	}
}

void	print_map(char *map, t_dim *map_dim)
{
    write(1, map, (map_dim->width * (map_dim->height - 1)));
}
