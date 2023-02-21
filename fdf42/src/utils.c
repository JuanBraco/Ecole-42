/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:49:31 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/01 12:13:23 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_int(int **str, t_fdf *fdf)
{
	int	i;

	i = fdf->map.len_row - 1;
	while (i >= 0)
		free(str[i--]);
}

void	ft_free(void **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	ft_error(char *message, int exit_code, t_fdf *fdf)
{
	ft_putstr_fd(message, 1);
	ft_exit(fdf, exit_code);
}

void	ft_check(int *cols, int *rows, int len, t_fdf *fdf)
{
	if (len > *cols)
		*cols = len;
	if (*cols == len)
		*rows += 1;
	else
	{
		ft_putstr_fd("Not a valid file!!!", 1);
		free(fdf);
	}
}

void	ft_exit(t_fdf *fdf, int exit_code)
{
	free(fdf);
	exit(exit_code);
}
