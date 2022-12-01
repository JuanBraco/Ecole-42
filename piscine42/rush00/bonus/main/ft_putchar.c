/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:09:25 by amuller           #+#    #+#             */
/*   Updated: 2022/09/18 18:48:45 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_atoi(char *nbr)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (nbr[i])
	{
		nb *= 10;
		nb += nbr[i] - '0';
		i++;
	}
	return (nb);
}
