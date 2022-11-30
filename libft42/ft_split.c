/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:59:22 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 16:42:32 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_mot(char *str, char charset)
{
	int	a;

	a = 0;
	while (*str)
	{
		while (*str == charset)
			str++;
		if (*str != charset && *str)
		{
			a++;
			while (*str != charset && *str)
				str++;
		}
	}
	return (a);
}

static char	**ft_free_s(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	return (0);
}

static int	init_tab(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != charset && str[i] != '\0')
			i++;
	return (i);
}

static int	put_tab(char *str, char charset, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (*str != '\0' && nb_mot(str, charset))
	{
		while (*str == charset)
			str++;
		tab[i] = malloc(sizeof(char) * (init_tab(str, charset) + 1));
		if (!tab[i])
			return (i);
		j = 0;
		while (*str != charset && *str != '\0')
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
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		t;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (nb_mot((char *)s, c) + 1));
	if (tab == 0)
		return (0);
	t = put_tab((char *)s, c, tab);
	if (t)
		return (ft_free_s(tab, t));
	return (tab);
}
