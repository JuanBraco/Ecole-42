/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:48:06 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/04 00:26:02 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "init_print_tab.h"
#include "sq_made.h"
#include "include/map_check.h"

void	full_tab_init(char **tab, t_characters chars)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == chars.vide)
				tab[i][j] = '1';
			else if (tab[i][j] == chars.obstacle)
				tab[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	tab_nbr_square(char **tab)
{
	int	i;
	int	j;
	int	r1;
	int	c1;
	int	d1;

	i = 2;
	while (tab[i])
	{
		j = 1;
		while (tab[i][j])
		{
			r1 = val_r1(i, j, tab);
			c1 = val_c1(i, j, tab);
			d1 = val_d1(i, j, tab);
			if (tab[i][j] != '0')
				tab[i][j] = ft_min(r1, c1, d1) + 1;
			j++;
		}
		i++;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 1;
	while (tab[i] != 0)
	{
		printf("%s", tab[i]);
		printf("\n");
		i++;
	}
}

int	ft_min(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return (c);
		else
			return (b);
	}
	else
	{
		if (a > c)
			return (c);
		else
			return (a);
	}
}
