/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:31:35 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/15 18:51:15 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_nb(int a)
{
	char	c;
	char	d;

	c = '0' + a / 10;
	d = '0' + a % 10;
	ft_putchar(c);
	ft_putchar(d);
}

void	ft_print(int l, int k)
{
	ft_print_nb(l);
	ft_putchar(' ');
	ft_print_nb(k);
	if (l == 98)
	{
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	m;
	int	n;

	m = 0;
	while (m < 99)
	{
		n = m + 1;
		while (n < 100)
		{
			ft_print(m, n);
			n++;
		}
	m++;
	}
}
