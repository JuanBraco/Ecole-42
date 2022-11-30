/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:18 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 10:58:43 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int	*tab;
	
	tab = malloc(sizeof(int) * 4);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;

	void	ft(int a)
	{
		a = a + 1;
	}
	ft_foreach(tab, 4, &ft);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	
	
}*/
