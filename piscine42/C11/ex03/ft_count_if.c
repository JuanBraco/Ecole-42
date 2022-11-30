/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:32:19 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 10:40:53 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			a++;
		i++;
	}
	return (a);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	**tab;
	
	
	tab = malloc(sizeof(int) * 4);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;

	int	ft(int a)
	{
		if (a % 2 == 0)
			return (1);
		return (0);
	}
	tab = ft_count_if(tab, 4, &ft);
	printf("%d\n", tab);
	//printf("%d\n", tab[1]);
	//printf("%d\n", tab[2]);
	//printf("%d\n", tab[3]);	
}*/
