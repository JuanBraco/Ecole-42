/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:49 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 12:12:55 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define MAX_X (10)
# define MAX_ZOOM (5)
# define MAGIC_ZOOM (-10)
# define WIDTH (1280)
# define HEIGHT (720)

typedef struct s_img
{
	int		line_len;
	int		endian;
	int		bpp;
	void	*mlx_img;
	char	*addr;
}			t_img;

typedef struct s_point
{
	int		x;
	int		y;
	int		color;
}			t_point;

typedef struct s_slope
{
	t_point	start;
	t_point	end;
	t_point	cur;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		error;
	int		e2;
}			t_slope;

typedef struct s_map
{
	int		**val;
	int		**color;
	int		len_col;
	int		len_row;
	int		co_x;
	int		co_y;
	int		trans_x;
	int		trans_y;
	int		zoom;
	int		view;
	int		z_value;
	double	angle;
	char	*line;
}			t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}			t_mlx;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
}			t_fdf;

void		free_all(t_fdf *fdf);

// color.c

int			get_color(t_slope *slope);
int			get_color_alt(int alt, int input);

// utils.c

void		ft_free(void **str);
int			nb_abs(int nb);
void		ft_error(char *message, int exit_code, t_fdf *fdf);
void		ft_check(int *cols, int *rows, int len, t_fdf *fdf);
void		ft_exit(t_fdf *fdf, int exit_code);
void		ft_free_int(int **str, t_fdf *fdf);
void		my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

// read.c

int			ft_open(char *map_file, t_fdf *fdf);
void		ft_read_map(char *map_file, t_fdf *fdf);

// pixel.c

void		ft_print_pixel(int i, int j, t_fdf *fdf, int cas);

//init.c

int			ft_draw(t_fdf *fdf);
void		ft_atoi_bis(const char *nptr, t_fdf *fdf, int x, int y);

// key.c

int			close_win(t_fdf *fdf);
int			event_key(int key, t_fdf *fdf);

#endif