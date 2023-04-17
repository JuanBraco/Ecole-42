/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_in_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:18:36 by avast             #+#    #+#             */
/*   Updated: 2023/03/17 12:27:05 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_error(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	*ft_fill_chars_1(char *s, char c, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tab[0] = ft_calloc(i + 1, sizeof(char));
	if (!tab[0])
	{
		ft_free_error(tab, 0);
		return (NULL);
	}
	j = 0;
	while (*s != c && *s)
	{
		tab[0][j] = *s;
		s++;
		j++;
	}
	tab[0][j] = '\0';
	return (tab[0]);
}

static char	*ft_fill_chars_2(char *s, char c, char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!*s)
		return (NULL);
	if (*s == c)
		s++;
	while (s[i])
		i++;
	tab[1] = ft_calloc(i + 1, sizeof(char));
	if (!tab[1])
	{
		ft_free_error(tab, 1);
		return (NULL);
	}
	j = 0;
	while (*s)
	{
		tab[1][j] = *s;
		s++;
		j++;
	}
	tab[1][j] = '\0';
	return (tab[1]);
}

char	**ft_split_in_two(char *s, char c)
{
	char	**tab;

	if (s == 0)
		return (0);
	tab = ft_calloc(3, sizeof(char *));
	if (!tab)
		return (0);
	tab[0] = ft_fill_chars_1(s, c, tab);
	if (!tab[0])
		return (NULL);
	while (*s != c && *s)
		s++;
	tab[1] = ft_fill_chars_2(s, c, tab);
	tab[2] = NULL;
	return (tab);
}

/* 
int main(int argc, char **argv)
{
	char **tab;
	(void)argc;

	tab = ft_split_in_two(argv[1], '=');
	int i = 0;
	while (tab[i])
	{
		ft_printf("chaine %d = %s\n", i, tab[i]);
		i++;
	}
	ft_free_error(tab, 2);
	return (0);
}
 */