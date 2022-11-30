/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:38:43 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/26 16:15:28 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	unsigned int	a;

	a = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		a = a * nb;
		nb--;
	}
	return (a);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d", ft_iterative_factorial(5));
}*/
