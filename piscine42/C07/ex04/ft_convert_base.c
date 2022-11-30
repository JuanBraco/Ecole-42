/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:57:05 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/29 17:55:12 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	test_base(char *b);
int	ft_atoi_base(char *str, char *base);

int	ft_sizenbr_base(long nbr, char *base)
{
	int		i;

	i = 0;
	if (test_base(base) == 1)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			i++;
		}
		while (nbr > 0)
		{
			nbr = nbr / ft_strlen(base);
			i++;
		}
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, int size, char *c)
{
	long	w;
	long	nb_l;
	int		i;

	i = size - 1;
	nb_l = nbr;
	if (nb_l == 0)
		c[0] = base[0];
	if (nb_l < 0)
	{
		nb_l = -nb_l;
		c[0] = '-';
	}
	while (nb_l > 0)
	{
		w = nb_l % ft_strlen(base);
		nb_l = nb_l / ft_strlen(base);
		c[i] = base[w];
		i--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	tmp;
	int		size;
	char	*c;

	if (test_base(base_from) == 0 || test_base(base_to) == 0)
		return (0);
	tmp = ft_atoi_base(nbr, base_from);
	size = ft_sizenbr_base(tmp, base_to);
	c = malloc(sizeof(char) * (size + 1));
	if (c == 0)
		return (0);
	c[size] = '\0';
	ft_putnbr_base(tmp, base_to, size, c);
	return (c);
}

/*int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}*/
