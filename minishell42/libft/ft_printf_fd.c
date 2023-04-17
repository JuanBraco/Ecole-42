/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:27:56 by avast             #+#    #+#             */
/*   Updated: 2023/03/01 13:34:00 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putlongnbr_fd(long int nbr, int fd)
{
	if (nbr < 0)
	{	
		nbr = -1 * nbr;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	if (ft_putchar_fd(nbr % 10 + '0', fd) == -1)
		return (-1);
	return (0);
}

static int	ft_puthexa_fd(unsigned long long int nbr, char *base, int fd)
{
	if (nbr > 15)
		ft_puthexa_fd((nbr / 16), base, fd);
	if (ft_putchar_fd(base[nbr % 16], fd) == -1)
		return (-1);
	return (0);
}

static int	ft_putad_fd(unsigned long long int p, int fd)
{
	if (p == 0)
	{
		if (ft_putstr_fd("(nil)", fd) == -1)
			return (-1);
		return (0);
	}
	if (ft_putstr_fd("0x", fd) == -1)
		return (-1);
	if (ft_puthexa_fd(p, "0123456789abcdef", fd) == -1)
		return (-1);
	return (0);
}

static int	call_utils_fd(char c, int fd, va_list ap)
{
	int	a;

	if (c == 'c')
		a = ft_putchar_fd((char)va_arg(ap, int), fd);
	else if (c == 's')
		a = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (c == 'p')
		a = ft_putad_fd(va_arg(ap, unsigned long long int), fd);
	else if (c == 'd' || c == 'i')
		a = ft_putlongnbr_fd((long int)va_arg(ap, int), fd);
	else if (c == 'u')
		a = ft_putlongnbr_fd((long int)va_arg(ap, unsigned int), fd);
	else if (c == 'x')
		a = ft_puthexa_fd(va_arg(ap, unsigned int), "0123456789abcdef", fd);
	else if (c == 'X')
		a = ft_puthexa_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", fd);
	else if (c == '%')
		a = ft_putchar_fd('%', fd);
	if (a == -1)
		return (-1);
	return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			if (ft_putchar_fd(*format, fd) == -1)
				return (-1);
			format++;
		}
		if (*format == '%')
			format++;
		if (*format)
		{
			if (call_utils_fd(*format, fd, ap) == -1)
				return (-1);
			format++;
		}
	}
	va_end(ap);
	return (0);
}
