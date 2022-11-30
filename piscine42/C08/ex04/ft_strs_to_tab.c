/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:14:26 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/28 20:31:56 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (ptr == 0)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab_struct;

	i = 0;
	tab_struct = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab_struct == 0)
		return (tab_struct);
	while (i < ac)
	{
		tab_struct[i].size = ft_strlen(av[i]);
		tab_struct[i].str = av[i];
		tab_struct[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab_struct[i].size = 0;
	tab_struct[i].str = 0;
	tab_struct[i].copy = 0;
	return (tab_struct);
}

/*void				ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}*/
