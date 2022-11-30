/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:34 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 12:20:53 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_split.h"

int	c_in_charset(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j] != '\0')
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	nb_mot(char *str, char *charset)
{
	int	a;

	a = 0;
	while (*str != '\0')
	{
		while (c_in_charset(*str, charset))
		{
			str++;
		}
		while (!c_in_charset(*str, charset) && *str != '\0')
		{
			a++;
			str++;
		}
	}
	return (a);
}

void	put_tab(char *str, char *charset, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (*str != '\0')
	{
		while (c_in_charset(*str, charset))
			str++;
		j = 0;
		while (!c_in_charset(str[j], charset) && str[j] != '\0')
			j++;
		tab[i] = malloc(sizeof (char) * (j + 1));
		j = 0;
		while (!c_in_charset(*str, charset) && *str != '\0')
		{
			tab[i][j] = *str;
			j++;
			str++;
		}
		tab[i][j] = 0;
		if (tab[i][0] != '\0')
			i++;
	}
	tab[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (nb_mot(str, charset) + 1));
	if (tab == 0)
		return (0);
	put_tab(str, charset, tab);
	return (tab);
}
