/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:55:25 by avast             #+#    #+#             */
/*   Updated: 2022/11/10 19:09:54 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free_error(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	*ft_fill_chars(char *s, char c, char **tab, int index)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tab[index] = ft_calloc(i + 1, sizeof(char));
	if (!tab[index])
	{
		ft_free_error(tab, index);
		return (0);
	}
	j = 0;
	while (*s != c && *s)
	{
		tab[index][j] = *s;
		s++;
		j++;
	}
	tab[index][j] = '\0';
	return (tab[index]);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		size;
	char	**tab;

	if (s == 0)
		return (0);
	size = ft_count_words(s, c);
	tab = ft_calloc(size + 1, sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			tab[i] = ft_fill_chars(s, c, tab, i);
		if (!tab[i])
			return (0);
		while (*s != c && *s)
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
