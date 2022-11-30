/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:23:08 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/03 21:34:35 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "check_map.h"
#include "map_check.h"

int	check_line_len(char *map)
{
	int	i;
	int	line_len;
	int	prev_line_len;

	prev_line_len = -1;
	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	i++;
	while (map[i])
	{
		line_len = 0;
		while (map[i + line_len] && map[i + line_len] != '\n')
			line_len++;
		i += line_len;
		if (prev_line_len != -1 && prev_line_len != line_len)
			return (0);
		prev_line_len = line_len;
		i++;
	}
	if (!map[i] && map[i - 1] != '\n')
		return (0);
	return (1);
}

int	check_min_size(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	i++;
	if (map[i] && map[i] != '\n')
		return (1);
	return (0);
}

int	check_valid_chars(char *map)
{
	t_characters	chars;

	get_characters(&chars, map);
	while (*map && *map != '\n')
		map++;
	map++;
	while (*map)
	{
		if (*map != chars.vide && *map != chars.plein
			&& *map != chars.obstacle && *map != '\n')
			return (0);
		map++;
	}
	return (1);
}

int	check_map(char *map)
{
	if (!check_char(map) || !check_min_size(map)
		|| !check_line_len(map) || !check_char(map)
		|| !check_valid_chars(map))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}