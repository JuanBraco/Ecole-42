/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:21:54 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 11:04:02 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_add(int a, int b);
int	ft_sous(int a, int b);
int	ft_mul(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	s = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + str[i] - 48;
		i++;
	}
	return (nb * s);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		c = '0' + nb % 10;
		nb = nb / 10;
		if (nb > 0)
		{
			ft_putnbr(nb);
		}
		write(1, &c, 1);
	}
}

int	error_check(char *op, int str)
{
	if (op[0] == '/' && str == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op[0] == '%' && str == 0)
	{
		write(1, "Stop : modulo by zero\n", 24);
		return (0);
	}
	if (op[0] != '/' && op[0] != '%' && op[0] != '-'
		&& op[0] != '+' && op[0] != '*')
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{	
	int	(*f[5])(int, int);

	f[0] = &ft_add;
	f[1] = &ft_sous;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (ac != 4)
		return (0);
	if (!error_check(av[2], ft_atoi(av[3])))
		return (0);
	if (av[2][0] == '+')
		ft_putnbr((*f[0])(ft_atoi(av[1]), ft_atoi(av[3])));
	else if (av[2][0] == '-')
		ft_putnbr((*f[1])(ft_atoi(av[1]), ft_atoi(av[3])));
	else if (av[2][0] == '*')
		ft_putnbr((*f[2])(ft_atoi(av[1]), ft_atoi(av[3])));
	else if (av[2][0] == '/')
		ft_putnbr((*f[3])(ft_atoi(av[1]), ft_atoi(av[3])));
	else if (av[2][0] == '%')
		ft_putnbr((*f[4])(ft_atoi(av[1]), ft_atoi(av[3])));
	write(1, "\n", 1);
}
