/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:11:45 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/27 21:40:10 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	i = 0;
	if (min >= max)
	{
		ptr = 0;
		return (ptr);
	}
	ptr = malloc(sizeof(int) * (max - min));
	if (ptr == 0)
		return (0);
	while (i < (max - min))
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
