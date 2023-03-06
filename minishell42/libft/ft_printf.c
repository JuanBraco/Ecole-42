/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:27:56 by avast             #+#    #+#             */
/*   Updated: 2023/02/17 17:01:55 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	call_utils(char c, int *a, va_list ap)
{
	if (c == 'c')
		ft_putchar_pf((char)va_arg(ap, int), a);
	else if (c == 's')
		ft_putstr_pf(va_arg(ap, char *), a);
	else if (c == 'p')
		ft_putad_pf(va_arg(ap, unsigned long long int), a);
	else if (c == 'd' || c == 'i')
		ft_putnbr_pf((long int)va_arg(ap, int), a);
	else if (c == 'u')
		ft_putnbr_pf((long int)va_arg(ap, unsigned int), a);
	else if (c == 'x')
		ft_puthexa(va_arg(ap, unsigned int), "0123456789abcdef", a);
	else if (c == 'X')
		ft_puthexa(va_arg(ap, unsigned int), "0123456789ABCDEF", a);
	else if (c == '%')
		ft_putchar_pf('%', a);
}

int	ft_printf(const char *format, ...)
{
	int		a;
	va_list	ap;

	a = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			ft_putchar_pf(*format, &a);
			format++;
		}
		if (*format == '%')
			format++;
		if (*format)
		{
			call_utils(*format, &a, ap);
			format++;
		}
	}
	va_end(ap);
	return (a);
}
