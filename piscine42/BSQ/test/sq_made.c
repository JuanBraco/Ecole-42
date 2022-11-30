/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_made.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:17:40 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 22:23:57 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_map.h"
#include "ft_split.h"
#include "init_print_tab.h"
#include "sq_made.h"
#include "include/map_check.h"

struct t_point	pos_square(char **tab)
{
	int				i;
	int				j;
	struct t_point	sqr;

	i = 1;
	sqr.size_sq = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] > (sqr.size_sq + 48))
			{
				sqr.pos_r = i;
				sqr.pos_c = j;
				sqr.size_sq = tab[i][j] - 48;
			}
			j++;
		}
		i++;
	}
	return (sqr);
}

void	write_square(char **tab, struct t_point sqr, t_characters chars)
{
	int	i;
	int	j;

	i = 0;
	while (i < sqr.size_sq)
	{
		j = 0;
		while (j < sqr.size_sq)
		{
			tab[sqr.pos_r - i][sqr.pos_c - j] = chars.plein;
			j++;
		}
		i++;
	}
}

char	val_r1(int posr, int posc, char **tab)
{
	return (tab[posr - 1][posc]);
}

char	val_c1(int posr, int posc, char **tab)
{
	return (tab[posr][posc - 1]);
}

char	val_d1(int posr, int posc, char **tab)
{
	return (tab[posr - 1][posc - 1]);
}
