/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:19:13 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/28 12:00:47 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_char(char c, va_list params)
{
	char	*str;
	char	d;

	if (c == 'c')
	{
		d = va_arg(params, int);
		write(1, &d, 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(params, char *);
		if (str == 0)
		{
			write(1, "(null)", 6);
			return (6);
		}
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	return (0);
}

int	type_base(char c, va_list params)
{
	if (c == 'd' || c == 'i')
		return (l_i_s(ft_putnbr_pf(va_arg(params, int), 1), 10));
	else if (c == 'u')
		return (l_i_u(ft_putnbru_fd(va_arg(params, unsigned int), 1), 10));
	if (c == 'x')
		return (l_i_u(ft_putnbr16_fd(va_arg(params, unsigned int), 1,
					"0123456789abcdef"), 16));
	else if (c == 'X')
		return (l_i_u(ft_putnbr16_fd(va_arg(params, unsigned int), 1,
					"0123456789ABCDEF"), 16));
	return (0);
}

int	type_other(char c, va_list params)
{
	void	*str;

	if (c == '%')
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c == 'p')
	{
		str = va_arg(params, void *);
		if (str == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		else
		{
			write(1, "0x", 2);
			return (2 + l_i_up(ft_putptr_pf((unsigned long)str, 1,
						"0123456789abcdef"), 16));
		}
	}
	return (0);
}

int	ft_type(char c, va_list params)
{
	if (c == 'c' || c == 's')
		return (type_char(c, params));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (type_base(c, params));
	if (c == '%' || c == 'p')
		return (type_other(c, params));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type(str[i], params);
		}
		else
		{
			write(1, &str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(params);
	return (len);
}

/*int	main(void)
{
	//void	*ptr;
	// *(int *)ptr = -1;
	//write (1, &ptr, 8);
	//printf("%p \n", ptr);
	//ft_printf("%p", ptr);
	
	ft_printf("%i \n",ft_printf("%u \n", -1));
	printf("%i",printf("%u \n", -1));
}*/