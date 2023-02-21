/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:54:40 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 12:08:55 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_point(t_slope *slope, t_fdf *fdf)
{
	fdf->map.co_x = slope->cur.x + WIDTH / 2;
	fdf->map.co_y = slope->cur.y + HEIGHT / 2 - fdf->map.zoom * fdf->map.len_row
		/ 2;
}

static void	put_line(t_fdf *fdf, t_slope *slope)
{
	while (1)
	{
		init_point(slope, fdf);
		if (fdf->map.co_x + fdf->map.trans_x < WIDTH && fdf->map.co_y < HEIGHT
			- 1 - fdf->map.trans_y && fdf->map.co_x + fdf->map.trans_x > 0
			&& fdf->map.co_y + fdf->map.trans_y > 0)
			my_mlx_pixel_put(fdf, fdf->map.co_x + fdf->map.trans_x,
				fdf->map.co_y + fdf->map.trans_y, get_color(slope));
		if (slope->cur.x == slope->end.x && slope->cur.y == slope->end.y)
			break ;
		(*slope).e2 = (*slope).error;
		if ((*slope).e2 > -(*slope).dx)
		{
			(*slope).error -= (*slope).dy;
			slope->cur.x += (*slope).sx;
		}
		if ((*slope).e2 < (*slope).dy)
		{
			(*slope).error += (*slope).dx;
			slope->cur.y += (*slope).sy;
		}
	}
}

void	init_proj(t_slope *slope, int i, int j, t_fdf *fdf)
{
	slope->start.x = (i * fdf->map.zoom - j * fdf->map.zoom)
		* cos(fdf->map.angle) * fdf->map.view + (1 - fdf->map.view) * i
		* fdf->map.zoom;
	slope->start.y = (-(fdf->map.val[j][i] * fdf->map.zoom / fdf->map.z_value)
			+ (i * fdf->map.zoom + j * fdf->map.zoom) * sin(fdf->map.angle))
		* fdf->map.view + (1 - fdf->map.view) * j * fdf->map.zoom;
	slope->start.color = get_color_alt(fdf->map.val[j][i],
			fdf->map.color[j][i]);
	slope->cur.x = slope->start.x;
	slope->cur.y = slope->start.y;
	slope->cur.color = slope->start.color;
	slope->dx = (nb_abs(slope->end.x - slope->start.x));
	if (slope->start.x < slope->end.x)
		slope->sx = 1;
	else
		slope->sx = -1;
	slope->dy = (nb_abs(slope->end.y - slope->start.y));
	if (slope->start.y < slope->end.y)
		slope->sy = 1;
	else
		slope->sy = -1;
	if (slope->dx > slope->dy)
		slope->error = slope->dx / 2;
	else
		slope->error = -slope->dy / 2;
}

void	init_slope(t_slope *slope, int i, int j, t_fdf *fdf)
{
	int		zoom;

	zoom = fdf->map.zoom;
	slope->end.x = (i * (zoom) - (j) * zoom) * cos(fdf->map.angle)
		* fdf->map.view + (1 - fdf->map.view) * i * zoom;
	slope->end.y = (-(fdf->map.val[j][i] * zoom / fdf->map.z_value) + (i
				* (zoom) + (j) * zoom) * sin(fdf->map.angle)) * fdf->map.view
		+ (1 - fdf->map.view) * j * zoom;
	slope->end.color = get_color_alt(fdf->map.val[j][i], fdf->map.color[j][i]);
}

void	ft_print_pixel(int i, int j, t_fdf *fdf, int cas)
{
	t_slope	*slope;

	slope = (t_slope *)malloc(sizeof(t_slope));
	if (!slope)
	{
		ft_putstr_fd("Memory Allocation failed!!!", 1);
		exit(0);
	}
	if (cas == 1)
	{
		init_slope(slope, i, (j + 1), fdf);
	}
	else
	{
		init_slope(slope, (i + 1), j, fdf);
	}
	init_proj(slope, i, j, fdf);
	if (slope->end.x != slope->start.x && slope->end.y != slope->start.y)
		put_line(fdf, slope);
	if (!fdf->map.view)
		put_line(fdf, slope);
	free(slope);
}
