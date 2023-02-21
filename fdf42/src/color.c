/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:48:07 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/31 10:57:42 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;
	double	d;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		d = 1.0;
	else
		d = (placement / distance);
	return (d);
}

static int	get_light(int start, int end, double percentage)
{
	int	color;

	color = (int)((1 - percentage) * start + percentage * end);
	return (color);
}

int	get_color(t_slope *slope)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (slope->cur.color == slope->end.color)
		return (slope->cur.color);
	if ((*slope).dx > (*slope).dy)
		percentage = percent(slope->start.x, slope->end.x, slope->cur.x);
	else
		percentage = percent(slope->start.y, slope->end.y, slope->cur.y);
	red = get_light((slope->start.color >> 16) & 0xFF,
			(slope->end.color >> 16) & 0xFF, percentage);
	green = get_light((slope->start.color >> 8) & 0xFF,
			(slope->end.color >> 8) & 0xFF, percentage);
	blue = get_light(slope->start.color & 0xFF, slope->end.color & 0xFF,
			percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	get_color_alt(int alt, int input)
{
	if (input == 0)
	{
		if (alt >= 1)
			return (0x00FF0000);
		else if (alt == 0)
			return (0x00FFFFFF);
		else
			return (0x00FFFFFF);
	}
	else
		return (input);
}
