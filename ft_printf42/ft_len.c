/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:53 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/28 11:54:37 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	l_i_s(long n, int b)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	l_i_u(unsigned int n, int b)
{
	int				i;
	unsigned long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	l_i_up(unsigned long n, int b)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}
