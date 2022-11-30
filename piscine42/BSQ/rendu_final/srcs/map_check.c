/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:08:12 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/03 23:12:42 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/check_map.h"
#include "../include/map_check.h"

int	first_line_len(char *map)
{
	int	len;

	while (map[len] && map[len] != '\n')
		len++;
	return (len);
}

int	check_char(char *map)
{
	int	i;
	int	j;
	int	line_len;

	line_len = first_line_len(map);
	i = 0;
	if (line_len < 3)
		return (0);
	while (map[i] && map[i] != '\n')
		i++;
	i--;
	while (i)
	{
		j = i - 1;
		while (j >= 0 && j > line_len - 4)
		{
			if (map[i] == map[j] || map[i] < 32 || map[i] == 127)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

void	get_characters(t_chars *chars, char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	i--;
	chars->plein = map[i];
	chars->obstacle = map[i - 1];
	chars->vide = map[i - 2];
}
