/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:15:36 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 10:30:47 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_int(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	long	nb;

	nb = n;
	len = l_int(n);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (NULL);
	if (nb == 0)
		*ptr = '0';
	if (nb < 0)
	{
		*ptr = '-';
		nb = -nb;
	}
	ptr[len--] = '\0';
	while (nb)
	{
		ptr[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (ptr);
}
