/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:05:52 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/09 17:08:45 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n, int fd)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	c = '0' + nb % 10;
	nb = nb / 10;
	if (nb > 0)
		ft_putnbr_pf(nb, fd);
	write(fd, &c, 1);
	return (n);
}

unsigned int	ft_putnbru_fd(unsigned int n, int fd)
{
	char			c;
	unsigned long	nb;

	nb = n;
	c = '0' + nb % 10;
	nb = nb / 10;
	if (nb > 0)
		ft_putnbru_fd(nb, fd);
	write(fd, &c, 1);
	return (n);
}

unsigned int	ft_putnbr16_fd(unsigned int n, int fd, char *base)
{
	char			c;
	unsigned long	nb;

	nb = n;
	c = base[nb % 16];
	nb = nb / 16;
	if (nb > 0)
	{
		ft_putnbr16_fd(nb, fd, base);
	}
	write(fd, &c, 1);
	return (n);
}

unsigned long	ft_putptr_pf(unsigned long n, int fd, char *base)
{
	char				c;
	unsigned long long	nb;

	nb = n;
	c = base[nb % 16];
	nb = nb / 16;
	if (nb > 0)
	{
		ft_putptr_pf(nb, fd, base);
	}
	write(fd, &c, 1);
	return (n);
}
