/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:20:29 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/01 17:30:35 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

/*#include <stdio.h>

int	main(void)
{
	char str[] = "     ";
	char c[] = "  ";
	char **tab = ft_split(str, c);
	//printf("%s\n", tab[0]);
	//printf("%s\n", tab[1]);
	//printf("%s\n", tab[2]);
	//printf("%s\n", tab[3]);
	//printf("%s\n", tab[4]);
	//printf("%s\n", tab[5]);
	//printf("%s\n", tab[6]);
	//printf("%s\n", tab[7]);
}*/
