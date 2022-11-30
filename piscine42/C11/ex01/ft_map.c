/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:28:30 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 10:59:05 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*str;

	i = 0;
	str = malloc(sizeof(int) * length);
	if (str == 0)
		return (0);
	while (i < length)
	{
		str[i] = f(tab[i]);
		i++;
	}
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int	*tab;
	int	*str;
	
	tab = malloc(sizeof(int) * 4);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;

	int	ft(int a)
	{
		a = a + 1;
		return (a);
	}
	str = ft_map(tab, 4, &ft);
	printf("%d\n", str[0]);
	printf("%d\n", str[1]);
	printf("%d\n", str[2]);
	printf("%d\n", str[3]);	
}*/
