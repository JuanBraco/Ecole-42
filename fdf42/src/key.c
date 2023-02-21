/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:34:34 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 09:59:52 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_win(t_fdf *param)
{
	mlx_destroy_image(param->mlx.init, param->img.mlx_img);
	mlx_destroy_window(param->mlx.init, param->mlx.win);
	mlx_destroy_display(param->mlx.init);
	free(param->mlx.init);
	ft_free_int(param->map.val, param);
	ft_free_int(param->map.color, param);
	free(param->map.val);
	free(param->map.color);
	free(param);
	exit(0);
}

int	translate_map(int key, t_fdf *param)
{
	if (key == XK_w)
		param->map.trans_y -= 20;
	else if (key == XK_s)
		param->map.trans_y += 20;
	else if (key == XK_a)
		param->map.trans_x -= 20;
	else if (key == XK_d)
		param->map.trans_x += 20;
	return (0);
}

int	alt_view(int key, t_fdf *param)
{
	if (key == XK_m)
	{
		if (param->map.z_value >= 4)
			param->map.z_value -= 1;
	}
	else if (key == XK_n)
	{
			param->map.z_value += 1;
	}
	else if (key == XK_i)
	{
		param->map.view = 1;
	}
	else if (key == XK_p)
	{
		param->map.view = 0;
	}
	return (0);
}

int	key_zoom(int key, t_fdf *param)
{
	if (key == XK_l)
		param->map.zoom += 2;
	else if (key == XK_k)
	{
		if (param->map.zoom < 2)
			param->map.zoom = 1;
		else
			param->map.zoom -= 2;
	}
	else if (key == XK_Escape)
	{
		mlx_destroy_image(param->mlx.init, param->img.mlx_img);
		mlx_destroy_window(param->mlx.init, param->mlx.win);
		mlx_destroy_display(param->mlx.init);
		free(param->mlx.init);
		ft_free_int(param->map.val, param);
		ft_free_int(param->map.color, param);
		free(param->map.val);
		free(param->map.color);
		free(param);
		exit(0);
	}
	return (0);
}

int	event_key(int key, t_fdf *param)
{
	key_zoom(key, param);
	translate_map(key, param);
	alt_view(key, param);
	mlx_destroy_image(param->mlx.init, param->img.mlx_img);
	param->img.mlx_img = mlx_new_image(param->mlx.init, WIDTH, HEIGHT);
	ft_draw(param);
	mlx_put_image_to_window(param->mlx.init, param->mlx.win, param->img.mlx_img,
		0, 0);
	mlx_string_put(param->mlx.init, param->mlx.win, WIDTH - 90, 10, 0xffffff,
		"By Juan Braco");
	mlx_string_put(param->mlx.init, param->mlx.win, 5, 60, 0xffffff,
		"Translate MAP : UP = W / DOWN = S / LEFT = A / RIGHT = D");
	mlx_string_put(param->mlx.init, param->mlx.win, 5, 80, 0xffffff,
		"ZOOM +/- : L/K");
	mlx_string_put(param->mlx.init, param->mlx.win, 5, 100, 0xffffff,
		"ALTITUDE VARIATION +/- : M/N");
	mlx_string_put(param->mlx.init, param->mlx.win, 5, 120, 0xffffff,
		"PROJECTION ISOMETRIC/PARALLEL : I/P");
	return (0);
}
