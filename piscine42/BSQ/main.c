/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:26:36 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/03 18:39:52 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/dimensions.h"

typedef struct Square
{
    int size;
    int x;
    int y;
} Square;

int is_ok(Square square, char *map, int height, int width)
{
    int row = square.y;
    int col = square.x;

    if (col + square.size > width || row + square.size > height)
        return (0);
    while (row < square.size + square.y)
    {
        col = square.x;
        while (col < square.size + square.x)
        {
            // printf("%c %d %d\n", map[col + (row * width)], square.x, square.y);
            if (map[col + (row * width)] == 'o')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}

void fill_map(Square square, char *map)
{
    int row = square.y;
    int col = square.x;
    int width = map_width(map) + 1;

    while (row < square.size + square.y)
    {
        int col = square.x;
        while (col < square.size + square.x)
        {
            map[col + (row * width)] = 'x';
            col++;
        }
        row++;
    }
}

Square solve(char *map)
{
    int width = map_width(map) + 1;
    int height = map_height(map);
    Square square;
    Square solution;

    solution.size = 0;
    solution.x = 0;
    solution.y = 0;
    square.size = 0;
    square.y = 0;
    while (square.y < height - square.size)
    {
        square.x = 0;
        while (square.x < width - square.size)
        {
            if (is_ok(square, map, height, width))
            {
                printf("%d\n", square.y);
                while (is_ok(square, map, height, width))
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

char *get_map()
{
    char *buf;
    int fd = open("map.txt",  O_RDONLY, 0);

    buf = (char *)malloc(1000000);
    read(fd, buf, 1000000);
    close(fd);
    return (buf);
}

void	print_map(char *map)
{
	int	row;
	int	height;
	int	width;
	int	col;

	height = map_height(map);
	width = map_width(map) + 1;
	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			write(1, &(map[col + row * width]), 1);
			col++;
		}
		row++;
	}
}

int main()
{
    char *map;
    int row = 0;
    int col = 0;

    map = get_map();
    map += 6;
    Square solution = solve(map);
    // printf("%d %d %d", solution.size, solution.x, solution.y);
    fill_map(solution, map);
    print_map(map);
    free(map - 6);
}
