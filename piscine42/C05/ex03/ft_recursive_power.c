/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:45:24 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/26 16:17:49 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	a;

	a = 1;
	if (nb == 1)
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power >= 1)
	{
		a = nb * ft_recursive_power(nb, power - 1);
	}
	return (a);
}

/*#include<stdio.h>
int main(void)
{
	printf("%d", ft_recursive_power(-5, 5));
}*/
