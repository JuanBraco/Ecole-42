/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:12:24 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/17 20:34:07 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_printable(char c)
{
	if (c < 32 || c >= 127)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	hexadec(char c)
{
	char	*f;
	char	d;
	char	e;
	int		a;
	int		b;

	f = "0123456789abcdef";
	a = c / 16;
	b = c % 16;
	d = f[a];
	e = f[b];
	ft_putchar(d);
	ft_putchar(e);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_printable(str[i]) == 1)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			hexadec(str[i]);
		}
	i++;
	}
}
