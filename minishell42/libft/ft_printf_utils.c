/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:08:45 by avast             #+#    #+#             */
/*   Updated: 2022/12/07 18:33:36 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_pf(char c, int *a)
{
	write(1, &c, 1);
	*a = *a + 1;
}

void	ft_putstr_pf(char *s, int *a)
{
	int	i;

	if (s == 0)
		ft_putstr_pf("(null)", a);
	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		ft_putchar_pf(s[i], a);
		i++;
	}
}

void	ft_putnbr_pf(long int nbr, int *a)
{
	if (nbr < 0)
	{	
		nbr = -1 * nbr;
		ft_putchar_pf('-', a);
	}
	if (nbr > 9)
		ft_putnbr_pf(nbr / 10, a);
	ft_putchar_pf(nbr % 10 + '0', a);
}

void	ft_puthexa(unsigned long long int nbr, char *base, int *a)
{
	if (nbr > 15)
		ft_puthexa((nbr / 16), base, a);
	ft_putchar_pf(base[nbr % 16], a);
}

void	ft_putad_pf(unsigned long long int p, int *a)
{
	if (p == 0)
	{
		ft_putstr_pf("(nil)", a);
		return ;
	}
	ft_putstr_pf("0x", a);
	ft_puthexa(p, "0123456789abcdef", a);
}
