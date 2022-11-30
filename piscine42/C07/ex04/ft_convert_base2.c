/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:03:07 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/27 10:09:29 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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

int	test_base(char *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(b) <= 1)
		return (0);
	while (b[i] != '\0')
	{
		if (b[i] == '+' || b[i] == '-' || (b[i] <= 13 && b[i] >= 9)
			|| b[i] == ' ')
			return (0);
		j = i + 1;
		while (b[j] != '\0')
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	pos_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	nb = 0;
	s = 1;
	if (test_base(base) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (pos_base(str[i], base) >= 0)
	{
		nb = ft_strlen(base) * nb + pos_base(str[i], base);
		i++;
	}
	return (nb * s);
}
