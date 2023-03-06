/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:08:45 by avast             #+#    #+#             */
/*   Updated: 2023/03/01 13:35:42 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_err_pf(char c, int *a)
{
	write(2, &c, 1);
	*a = *a + 1;
}

void	ft_putstr_err_pf(char *s, int *a)
{
	int	i;

	if (s == 0)
		ft_putstr_err_pf("(null)", a);
	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		ft_putchar_err_pf(s[i], a);
		i++;
	}
}

void	ft_putnbr_err_pf(long int nbr, int *a)
{
	if (nbr < 0)
	{	
		nbr = -1 * nbr;
		ft_putchar_err_pf('-', a);
	}
	if (nbr > 9)
		ft_putnbr_err_pf(nbr / 10, a);
	ft_putchar_err_pf(nbr % 10 + '0', a);
}

void	ft_puthexa_err(unsigned long long int nbr, char *base, int *a)
{
	if (nbr > 15)
		ft_puthexa_err((nbr / 16), base, a);
	ft_putchar_err_pf(base[nbr % 16], a);
}

void	ft_putad_err_pf(unsigned long long int p, int *a)
{
	if (p == 0)
	{
		ft_putstr_err_pf("(nil)", a);
		return ;
	}
	ft_putstr_err_pf("0x", a);
	ft_puthexa_err(p, "0123456789abcdef", a);
}
