/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:17:10 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/04 17:12:38 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	if (tab == 0)
		return (1);
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			a = 1;
		else if (f(tab[i], tab[i + 1]) < 0)
			b = 1;
		i++;
	}
	if (a + b == 2)
		return (0);
	return (1);
}
