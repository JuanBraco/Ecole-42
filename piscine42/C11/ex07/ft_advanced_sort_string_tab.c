/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:35:39 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 10:58:19 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;

	//int	ft_strcmp(char *a, char *b)
	//{
	//	int	i;

	//	i = 0;
	//	while (a[i] && b[i] && a[i] == b[i])
	//		i++;
	//	return (a[i] - b[i]);
	//}
	int	ft_strcmplen(char *a, char *b)
	{
		int	i;
		int	j;

		i = 0;
		j = 0;
		while (a[i])
			i++;
		while (b[j])
			j++;
		return (i - j);
	}
	ft_advanced_sort_string_tab(av, &ft_strcmplen);
	printf("%s\n", av[0]);
	printf("%s\n", av[1]);
	printf("%s\n", av[2]);
	printf("%s\n", av[3]);
	printf("%s\n", av[4]);
	printf("%s\n", av[5]);
	printf("%s\n", av[6]);
}*/
