/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:50:55 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/26 16:14:38 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{
	unsigned int	r;

	r = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		r = nb * ft_recursive_factorial(nb - 1);
	}
	return (r);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d", ft_recursive_factorial(2));
}*/
