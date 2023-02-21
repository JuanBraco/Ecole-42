/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:01:56 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/19 14:59:55 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == '0' || s1[i] == '+')
		i++;
	while (s2[j] == '0' || s2[j] == '+')
		j++;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

static int	ft_is_number(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '0' || av[i] == '+' || av[i] == '-') && av[i + 1])
		i++;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_doubles(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_check(int ac, char **av)
{
	long int	nb;
	int			i;

	i = 1;
	nb = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		if (ft_is_number(av[i]) == 1)
			return (1);
		i++;
	}
	if (ft_check_doubles(av) == 1)
		return (1);
	return (0);
}
