/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:27:56 by avast             #+#    #+#             */
/*   Updated: 2023/03/01 13:34:00 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	call_utils_err(char c, int *a, va_list ap)
{
	if (c == 'c')
		ft_putchar_err_pf((char)va_arg(ap, int), a);
	else if (c == 's')
		ft_putstr_err_pf(va_arg(ap, char *), a);
	else if (c == 'p')
		ft_putad_err_pf(va_arg(ap, unsigned long long int), a);
	else if (c == 'd' || c == 'i')
		ft_putnbr_err_pf((long int)va_arg(ap, int), a);
	else if (c == 'u')
		ft_putnbr_err_pf((long int)va_arg(ap, unsigned int), a);
	else if (c == 'x')
		ft_puthexa_err(va_arg(ap, unsigned int), "0123456789abcdef", a);
	else if (c == 'X')
		ft_puthexa_err(va_arg(ap, unsigned int), "0123456789ABCDEF", a);
	else if (c == '%')
		ft_putchar_err_pf('%', a);
}

int	ft_printf_err(const char *format, ...)
{
	int		a;
	va_list	ap;

	a = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			ft_putchar_err_pf(*format, &a);
			format++;
		}
		if (*format == '%')
			format++;
		if (*format)
		{
			call_utils_err(*format, &a, ap);
			format++;
		}
	}
	va_end(ap);
	return (a);
}
