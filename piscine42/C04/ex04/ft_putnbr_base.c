/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:41:34 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/04 18:44:40 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	test_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	w;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (test_base(base) == 1)
		{
			if (nbr < 0)
			{
				nbr = -nbr;
				write(1, "-", 1);
			}
			w = nbr % ft_strlen(base);
			nbr = nbr / ft_strlen(base);
			if (nbr > 0)
				ft_putnbr_base(nbr, base);
			write(1, &base[w], 1);
		}
	}
}

/*#include <stdio.h>
int		main(void)
{
	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(40, "abcd");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(1526, "0123456789abcdef");
}*/
