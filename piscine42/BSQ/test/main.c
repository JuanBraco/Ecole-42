/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:17:49 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 23:36:39 by jde-la-f         ###   ########.fr       */
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
#include "include/check_map.h"
#include "include/map_check.h"

int	main(int ac, char **av)
{
	t_characters	chars;
	struct t_point	pos;	
	char			*c;
	char			**tab;
	int				i;

	i = 1;
	if (ac == 1)
		i--;
	while (i < ac)
	{
		get_map(&c, av[i], ac);
		if (check_map(c))
		{
			get_characters(&chars, c);
			tab = ft_split(c, "\n");
			full_tab_init(tab, chars);
			tab_nbr_square(tab);
			pos = pos_square(tab);
			tab = ft_split(c, "\n");
			write_square(tab, pos, chars);
			print_tab(tab);
			if (i < ac - 1)
				write(1, "\n", 1);
		}
		else
			if (i < ac - 1)
				write(1, "\n", 1);
		i++;
	}
	return (0);
}
