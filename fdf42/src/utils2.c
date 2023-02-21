/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:00:24 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/31 15:30:02 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	is_hexa(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static int	ft_check_color(const char *nptr, int i)
{
	int	res;

	res = 0;
	if (nptr[i] == ',')
	{
		i++;
		while (nptr[i] == '0' || nptr[i] == 'x')
			i++;
		while (nptr[i])
		{
			res *= 16;
			res = res + is_hexa(nptr[i]);
			i++;
		}
		return (res);
	}
	else
		return (0);
}

void	ft_atoi_bis(const char *nptr, t_fdf *fdf, int x, int y)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	s = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = 10 * nb + nptr[i] - 48;
		i++;
	}
	fdf->map.val[y][x] = (nb * s);
	fdf->map.color[y][x] = ft_check_color(nptr, i);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = fdf->img.addr + (y * fdf->img.line_len + x * (fdf->img.bpp / 8));
	*(int *)pixel = color;
}
