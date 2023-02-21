/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:59:03 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 11:59:38 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_open(char *map_file, t_fdf *fdf)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening", 1, fdf);
	return (fd);
}

static void	init_map(t_fdf *fdf)
{
	fdf->map.trans_x = 0;
	fdf->map.trans_y = 0;
	fdf->map.z_value = 10.00;
	fdf->map.angle = 0.523599;
	if (fdf->map.len_col > fdf->map.len_row)
		fdf->map.zoom = (WIDTH / (fdf->map.len_col * 3));
	else
		fdf->map.zoom = (HEIGHT / (fdf->map.len_row * 3));
	if (fdf->map.zoom == 0)
		fdf->map.zoom = 1;
	fdf->map.view = 1;
	fdf->mlx.init = mlx_init();
	if (!fdf->mlx.init)
	{
		ft_free((void **)fdf->map.val);
		ft_free((void **)fdf->map.color);
		free(fdf);
		ft_error("Error mlx", 1, fdf);
	}
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIDTH, HEIGHT, "FDF");
	fdf->img.mlx_img = mlx_new_image(fdf->mlx.init, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
}

int	ft_draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.len_col)
	{
		j = 0;
		while (j < fdf->map.len_row)
		{
			if (j < fdf->map.len_row - 1)
				ft_print_pixel(i, j, fdf, 1);
			if (i < fdf->map.len_col - 1)
				ft_print_pixel(i, j, fdf, 2);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_all(t_fdf *fdf)
{
	free(fdf->mlx.init);
	ft_free((void **)fdf->map.val);
	ft_free((void **)fdf->map.color);
	free(fdf->map.val);
	free(fdf->map.color);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
	{
		ft_putstr_fd("Memory Allocation failed!!!", 1);
		exit(0);
	}
	if (argc == 2)
	{
		ft_read_map(argv[1], fdf);
		init_map(fdf);
		ft_draw(fdf);
		mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->img.mlx_img,
			0, 0);
		mlx_hook(fdf->mlx.win, 17, 0L, close_win, fdf);
		mlx_key_hook(fdf->mlx.win, event_key, fdf);
		mlx_loop(fdf->mlx.init);
		free_all(fdf);
	}
	else
		ft_error("Error : Too many or no map", 1, fdf);
	return (0);
}
