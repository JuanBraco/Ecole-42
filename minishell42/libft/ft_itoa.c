/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:45 by avast             #+#    #+#             */
/*   Updated: 2022/11/10 14:48:20 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_size(int n)
{
	long int	nbr;
	int			size;

	nbr = n;
	size = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		size++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*nbr_str;
	long int	nbr;

	size = number_size(n);
	nbr = n;
	nbr_str = ft_calloc(size + 1, sizeof(char));
	if (!nbr_str)
		return (0);
	nbr_str[size] = '\0';
	if (nbr == 0)
		nbr_str[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		nbr_str[0] = '-';
	}
	while (nbr > 0)
	{
		nbr_str[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (nbr_str);
}
