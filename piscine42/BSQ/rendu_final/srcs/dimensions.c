/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:38:01 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/03 18:39:12 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/dimensions.h"

int	map_width(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int	map_height(char *map, int width)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
		i++;
	return (i / width);
}
